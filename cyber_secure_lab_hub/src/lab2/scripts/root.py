#!/usr/bin/env python3
import rospy
from std_msgs.msg import String
from ca import CA

ca = CA('/root/catkin_ws/tls')
ca.gen_rsa_priv()
ca.get_priv_details()
ca.gen_root_certificate('/root/catkin_ws/tls/openssl.cnf')

rospy.init_node('root', anonymous=True)  

pub = rospy.Publisher('root_ca', String, queue_size=10)

rate = rospy.Rate(10)

root_ca = String()

root_ca.data = 'abc'


def callback(data):
    rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.data)    
    

def listener():
    rospy.init_node('root', anonymous=True)  
    rospy.Subscriber('chatter', String, callback)   
    rospy.spin()
    
if __name__ == '__main__': 
    while not rospy.is_shutdown():
        pub.publish(root_ca)
        rate.sleep()   
        listener()