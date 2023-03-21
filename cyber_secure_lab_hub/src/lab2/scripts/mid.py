#!/usr/bin/env python3
import rospy
from std_msgs.msg import String
from ca import CA

ca = CA('/root/catkin_ws/tls')

pub = rospy.Publisher('pub_with_sub', String, queue_size=10)

def callback(data):
    rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.data)    
    # pub.publish(data)

def listener():
    rospy.init_node('mid', anonymous=True)  
    rospy.Subscriber('/root/root_ca', String, callback)   
    rospy.spin()
    
if __name__ == '__main__':    
    listener()