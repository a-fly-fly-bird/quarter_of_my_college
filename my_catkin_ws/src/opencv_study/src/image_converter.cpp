#include <ros/ros.h>
// Using image_transport for publishing and subscribing to images in ROS allows you to subscribe to compressed image streams.
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
// some useful constants and functions related to image encodings.
#include <sensor_msgs/image_encodings.h>
// OpenCV's image processing and GUI modules.
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
// 读入图片需要的库
#include "opencv2/imgcodecs/legacy/constants_c.h"
#include "opencv2/imgproc/types_c.h"

static const std::string OPENCV_WINDOW = "Image window";

class ImageConverter
{
private:
    ros::NodeHandle nh_;
    // image_transport类：图像传输类，其功能和ROS中的Publisher和Subscriber差不多，但是不同的是这个类在发布和订阅图片消息的同时还附带这摄像头的信息。
    // 相比较之下, 在ROS中传送图片信息，使用image_transport类要高效的多。
    image_transport::ImageTransport it_;
    image_transport::Subscriber image_sub_;
    image_transport::Publisher image_pub_;

public:
    ImageConverter()
        : it_(nh_)
    {
        // Subscrive to input video feed and publish output video feed
        image_sub_ = it_.subscribe("/camera/image_raw", 1,
                                   &ImageConverter::ImageCb, this);
        image_pub_ = it_.advertise("/image_converter/output_video", 1);

        // OpenCV HighGUI calls to create/destroy a display window on start-up/shutdown.
        cv::namedWindow(OPENCV_WINDOW);
    }

    ~ImageConverter()
    {
        cv::destroyWindow(OPENCV_WINDOW);
    }

    void ImageCb(const sensor_msgs::ImageConstPtr &msg)
    {
        // CvBridge defines a CvImage type containing an OpenCV image, its encoding and a ROS header.
        // 中文说的话就是： cv_bidge::CvImage类：cv_bridge中提供的数据结构，里面包括OpenCV中的cv::Mat类型的图像信息，图像编码方式，ROS头文件等等。
        cv_bridge::CvImagePtr cv_ptr;
        // 如果要将 图片读入 Mat 并 发布的话， 核心代码：
        // cv::Mat image = cv::imread("path", CV_LOAD_IMAGE_COLOR);
        // sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();

        try
        {
            // Note that OpenCV expects color images to use BGR channel order.
            cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
        }
        catch (cv_bridge::Exception &e)
        {
            ROS_ERROR("cv_bridge exception: %s", e.what());
            return;
        }

        // Draw an example circle on the video stream
        if (cv_ptr->image.rows > 60 && cv_ptr->image.cols > 60)
            cv::circle(cv_ptr->image, cv::Point(50, 50), 10, CV_RGB(255, 0, 0));

        // Update GUI Window
        cv::imshow(OPENCV_WINDOW, cv_ptr->image);
        cv::waitKey(3);

        // Output modified video stream
        image_pub_.publish(cv_ptr->toImageMsg());
    }
};

int main(int argc, char **argv)
{
    ros::init(argc, argv, "image_converter");
    ImageConverter ic;
    ros::spin();
    return 0;
}