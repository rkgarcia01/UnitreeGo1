#!/usr/bin/env python3
import rospy 
import numpy 
from geometry_msgs.msg import Twist 



#Global Varaibles 
PI = 3.1415926535897   #PI/2 is a 90 degree rotation

;;;''

print("Starting square...")


def Square_parameters():
    print("Starting square...")
    rospy.init_node('square', anonymous=True)
    pub = rospy.Publisher('turtle1/cmd_vel',Twist, queue_size=10)
    rate = rospy.Rate(10) #we publish the velocity at 10hz 
    twist = Twist()

    while not rospy.is_shutdown(): 
        move_in_line(twist,pub,rate)
        rotate(twist,pub,rate)




def move_in_line(twist,pub,rate): 
    Distance = 1
    Distance_travled = 0
    speed= 1
    twist.linear.x = speed
    t0 = rospy.Time.now().to_sec()
    while (Distance_travled < Distance): 
        pub.publish(twist)
        print("In 'move_in_line' while loop")
        t1 = rospy.Time.now().to_sec()
        Distance_travled = speed * (t1-t0)
        rate.sleep()
    twist.linear.x = 0
    pub.publish(twist)


def rotate(twist,pub,rate): 
    angled_travled = 0
    angle_speed = 0.08
    twist.angular.z = angle_speed
    time0 = rospy.Time().now().to_sec()
    while (angled_travled < PI/2.0): 
        pub.publish(twist)
        print("In 'rotate' while loop")
        time1 = rospy.Time.now().to_sec()
        angled_travled = angle_speed*(time1-time0)
        rate.sleep()
    twist.angular.z = 0
    pub.publish(twist)




if __name__ == '__main__':
    try: 
        Square_parameters()
    except rospy.ROSInterruptException:
        pass











































'''
#!/usr/bin/env python3
import rospy
import numpy
from geometry_msgs.msg import Twist

rospy.init_node('square', anonymous=True)
pub = rospy.Publisher('turtle1/cmd_vel', Twist, queue_size=10)
rate = rospy.Rate(10) #we publish the velocity at 10hz


print('Starting square . . .')
#PI = 3.1415926535897
# TODO: Modify the code below so that the robot moves in a square
PI = 3.1415926535897   #PI/2 is a 90 degree rotation 
Distance = 3
Distance_travled = 0
speed = 1    # (degrees/sec)
angle_travled = 0
angle_speed = .02
i = 1

while not rospy.is_shutdown(): 
    #twist = Twist() 
    t0  = rospy.Time.now().to_sec()
    time0 = rospy.Time.now().to_sec()
    while (Distance_travled < Distance):
        twist = Twist()
        print("In first while loop")
        twist.linear.x = speed
        time1 = rospy.Time.now().to_sec()
        Distance_travled = speed*(time1-time0)
        pub.publish(twist)
        rate.sleep()
        if (Distance_travled >= Distance):
            print("Distance is >= Distance")
            break
    while (angle_travled <= PI/2.0):
        twist = Twist()
        #pub.publish(twist)
        print("In second While loop")
        twist.angular.z = angle_speed
        t1 = rospy.Time.now().to_sec()
        angle_travled = angle_speed*(t1-t0)
        pub.publish(twist)
        rate.sleep()
        print("Current angle_travled:", angle_travled)
        if (angle_travled >= PI/2.0):
            print("angle_travled >= PI/2.0")
            break
    #twist.angular.z = 0
    Distance_travled = 0
    angle_travled = 0
    #pub.publish(twist)
    #rate.sleep()
#pub.publish(twist)

'''

'''
 #Works for Linear action
twist = Twist()
time0 = rospy.Time.now().to_sec()
while (Distance_travled < Distance):
    twist.linear.x = speed 
    time1 = rospy.Time.now().to_sec()
    Distance_travled = speed*(time1-time0)
    pub.publish(twist)
    rate.sleep()
pub.publish(twist)
'''
 #Works for angular turn
'''
twist = Twist()
t0  = rospy.Time.now().to_sec()
while (angle_travled <= PI/2.0): 
    twist.angular.z = angle_speed
    t1 = rospy.Time.now().to_sec()
    print("This is what is stored in 't1'",t1)
    angle_travled = angle_speed*(t1-t0)
    print("Angle Travled: ", angle_travled)
    pub.publish(twist)
    rate.sleep()
pub.publish(twist)
'''