#!/usr/bin/env python
import rospy
import rsa
import pyfiglet
import sys
from cyber_security_lab_1.msg import Data
from my_utils import read_private_key, read_fernet_key, rsa_decrypt, fernet_decrypt, read_private_key


def receive_data_wrapper(data):
    encrypt_type = data.encryption_algorithm
    msg = data.encrypted_msg.data
    if encrypt_type == 'exit':
        sys.exit()
    elif encrypt_type == '1':
        key = read_fernet_key(
            '/root/catkin_ws/src/cyber_security_lab_1/scripts/key/fernet_key.key')
        decrypted_msg = fernet_decrypt(bytes(msg), key)
    elif encrypt_type == '2':
        private_key = read_private_key(
            '/root/catkin_ws/src/cyber_security_lab_1/scripts/key/privateKey.key')
        decrypted_msg = rsa_decrypt(msg, private_key)
    elif encrypt_type == '3':
        decrypted_msg = bytes(msg).decode('utf-8')
    else:
        decrypted_msg = None
    return decrypted_msg


def callback(data):
    decMessage = receive_data_wrapper(data)
    rospy.loginfo(f'接收成功，解密后的信息是：{decMessage}')
    rospy.loginfo('继续监听')


def listener():
    rospy.init_node('custom_listener', anonymous=True)
    rospy.Subscriber("custom_chatter", Data, callback)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()


if __name__ == '__main__':
    result = pyfiglet.figlet_format("Cryptal -- Listener")
    print(result)
    print('开始监听')
    listener()
