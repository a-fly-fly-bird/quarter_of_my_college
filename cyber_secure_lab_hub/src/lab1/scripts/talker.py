#!/usr/bin/env python
import rospy
from std_msgs.msg import Int32MultiArray
from cyber_security_lab_1.msg import Data
import rsa
import time
import sys
import pyfiglet
from rich.console import Console
from my_utils import read_public_key, read_fernet_key, rsa_encrypt, fernet_encrypt, hash

console = Console()

def bytes2ints(bytes):
    ints = []
    for byte in bytes:
        # tmp = int.from_bytes(byte, byteorder='big', signed=False)
        ints.append(byte)
    return ints


def encrypt_wrapper():
    msg = str(input('请输入需要加密的内容:'))
    choice = str(input('请选择加密方式(1是对称加密，2是非对称加密, 3是哈希加密，exit是退出):'))
    if choice == '1':
        key = read_fernet_key(
            '/root/catkin_ws/src/cyber_security_lab_1/scripts/key/fernet_key.key')
        encrypted_msg = fernet_encrypt(msg, key)
    elif choice == '2':
        public_key = read_public_key(
            '/root/catkin_ws/src/cyber_security_lab_1/scripts/key/publicKey.key')
        encrypted_msg = rsa_encrypt(msg, public_key)
    elif choice == '3':
        encrypted_msg = hash(msg)
    else:
        encrypted_msg = None
    return encrypted_msg, choice


def sent_data_wrapper(encrypted_msg, encrypt_type):
    # 很神奇，需要这样才能传过去
    int32MultiArray = Int32MultiArray()
    data = Data()
    ints = bytes2ints(encrypted_msg)
    int32MultiArray.data = ints
    data.encrypted_msg = int32MultiArray
    data.encryption_algorithm = encrypt_type
    return data


def talker():
    pub = rospy.Publisher('custom_chatter', Data, queue_size=100)
    rospy.init_node('custom_talker', anonymous=True)
    r = rospy.Rate(10)  # 10hz
    
    while not rospy.is_shutdown():
        encrypted_msg, choice = encrypt_wrapper()

        # 这里好像是ros的一个bug，网上很多issue
        # encrypted_msg = encrypted_msg.decode()
        # bb = ByteMultiArray()
        # bb.data = list(encrypted_msg)
        sent_data = sent_data_wrapper(encrypted_msg, choice)
        pub.publish(sent_data)
        console.print('传输成功', style='bold cyan')
        # rospy.loginfo('传输成功')
        if choice == 'exit':
            time.sleep(1)
            sys.exit()
        r.sleep()


if __name__ == '__main__':
    result = pyfiglet.figlet_format("Cryptal -- Talker")
    print(result)

    console.print("Hello", "World!", style="bold red")
    console.print(":smiley: :vampire: :pile_of_poo: :thumbs_up: :raccoon:")
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
