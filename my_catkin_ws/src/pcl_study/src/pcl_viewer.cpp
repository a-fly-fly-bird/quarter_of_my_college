#include <ros/ros.h>
// PCL specific includes
#include <sensor_msgs/PointCloud2.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl_ros/point_cloud.h>
#include <pcl/sample_consensus/ransac.h>
#include <pcl/sample_consensus/sac_model_plane.h>
#include <iostream>

using namespace std;

boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer1(new pcl::visualization::PCLVisualizer("Pcl Viewer"));

class PclViewer
{
private:
    ros::NodeHandle nh_;
    ros::Subscriber sub_;
    ros::Publisher pub_;

public:
    PclViewer()
    {
        sub_ = nh_.subscribe<sensor_msgs::PointCloud2>("/rslidar_points", 1, &PclViewer::cloud_cb, this);
        pub_ = nh_.advertise<pcl::PointCloud<pcl::PointXYZ>>("/pointcloud_output", 1);
    }

    void cloud_cb(const sensor_msgs::PointCloud2ConstPtr &input)
    {
        // 转化为PCL中的点云的数据格式
        // This header allows you to publish and subscribe pcl::PointCloud<T> objects as ROS messages. These appear to ROS as sensor_msgs/PointCloud2 messages, offering seamless interoperability with non-PCL-using ROS nodes.
        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);

        // PCL、ROS等各种类型的点云之间的转换: https://zhuanlan.zhihu.com/p/55958811
        pcl::fromROSMsg(*input, *cloud);
        // 可视化
        // 移除当前所有点云
        viewer1->removeAllPointClouds();
        // 添加输入的点云
        viewer1->addPointCloud(cloud, "realsense pcl");
        viewer1->updatePointCloud(cloud, "realsense pcl");
        viewer1->spinOnce(0.001);

        pub_.publish(*cloud);
    }
};

int main(int argc, char **argv)
{
    ros::init(argc, argv, "pcl");
    PclViewer pcl_viewer;
    ros::spin();
    return 0;
}