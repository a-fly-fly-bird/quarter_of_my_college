#include <iostream>
#include <string>
#include <fstream>
#include "smart_car.h"

using namespace std;

const string &Underpan::GetId() const
{
    return id_;
}

void Underpan::SetId(const string &id)
{
    id_ = id;
}

const string &Underpan::GetModel() const
{
    return model_;
}

void Underpan::SetModel(const string &model)
{
    model_ = model;
}

double Underpan::GetWheelBase() const
{
    return wheel_base_;
}

void Underpan::SetWheelBase(double wheel_base)
{
    wheel_base_ = wheel_base;
}

double Underpan::GetAxleTrack() const
{
    return axle_track_;
}

void Underpan::SetAxleTrack(double axle_track)
{
    axle_track_ = axle_track;
}

double Underpan::GetGroundClearance() const
{
    return ground_clearance_;
}

void Underpan::SetGroundClearance(double ground_clearance)
{
    ground_clearance_ = ground_clearance;
}

double Underpan::GetMinimumBendingRadius() const
{
    return minimum_bending_radius_;
}

void Underpan::SetMinimumBendingRadius(double minimum_bending_radius)
{
    minimum_bending_radius_ = minimum_bending_radius;
}

const string &Underpan::GetDriveForm() const
{
    return drive_form_;
}

void Underpan::SetDriveForm(const string &drive_form)
{
    drive_form_ = drive_form;
}

double Underpan::GetBatteryLife() const
{
    return battery_life_;
}

void Underpan::SetBatteryLife(double battery_life)
{
    battery_life_ = battery_life;
}

const string &Underpan::GetTireModel() const
{
    return tire_model_;
}

void Underpan::SetTireModel(const string &tire_model)
{
    tire_model_ = tire_model;
}

double Underpan::GetTireSize() const
{
    return tire_size_;
}

void Underpan::SetTireSize(double tire_size)
{
    Underpan::tire_size_ = tire_size;
}

void Underpan::Print() const
{
    cout << *this << endl;
}

bool Underpan::Save(const string &filename) const
{
    ofstream out(filename, ios::app);
    if (!out.is_open())
    {
        cout << "文件打开失败" << endl;
        return false;
    }
    out << *this << endl;
    out.close();
    return true;
}

ostream &operator<<(ostream &os, const Underpan &underpan)
{
    return os << "底盘的编号是:" << underpan.GetId() << endl
              << "型号是:" << underpan.GetModel() << endl
              << "轴距是: " << underpan.GetWheelBase() << " mm" << endl
              << "轮距是: " << underpan.GetAxleTrack() << " mm" << endl
              << "最小离地间隙是:" << underpan.GetGroundClearance() << " mm" << endl
              << "最小转弯半径是:" << underpan.GetMinimumBendingRadius() << " m" << endl
              << "驱动形式是:" << underpan.GetDriveForm() << endl
              << "最大行程是:" << underpan.GetBatteryLife() << " km" << endl
              << "轮胎型号是:" << underpan.GetTireModel() << endl
              << "轮胎尺寸是:" << underpan.GetTireSize() << " mm" << endl;
}

const string &AgxKits::GetModel() const
{
    return model_;
}

void AgxKits::SetModel(const string &model)
{
    model_ = model;
}

double AgxKits::GetAiHashrate() const
{
    return ai_hashrate_;
}

void AgxKits::SetAiHashrate(double ai_hashrate)
{
    ai_hashrate_ = ai_hashrate;
}

double AgxKits::GetCudaCoreNum() const
{
    return cuda_core_num_;
}

void AgxKits::SetCudaCoreNum(double cuda_core_num)
{
    cuda_core_num_ = cuda_core_num;
}

double AgxKits::GetTensorCore() const
{
    return tensor_core_;
}

void AgxKits::SetTensorCore(double tensor_core)
{
    tensor_core_ = tensor_core;
}

double AgxKits::GetMemory() const
{
    return memory_;
}

void AgxKits::SetMemory(double memory)
{
    memory_ = memory;
}

double AgxKits::GetStorage() const
{
    return storage_;
}

void AgxKits::SetStorage(double storage)
{
    storage_ = storage;
}

void AgxKits::Print() const
{
    cout << *this << endl;
}

bool AgxKits::Save(const string &filename) const
{
    ofstream out(filename, ios::app);
    if (!out.is_open())
    {
        cout << "文件打开失败" << endl;
        return false;
    }
    out << *this << endl;
    out.close();
    return true;
}

ostream &operator<<(ostream &os, const AgxKits &AgxKits)
{
    return os << "AGX组件的型号是:" << AgxKits.GetModel() << endl
              << "AI是:" << AgxKits.GetAiHashrate() << " TOPS" << endl
              << "CUDA核心是:" << AgxKits.GetCudaCoreNum() << endl
              << "Tensor CORE是:" << AgxKits.GetTensorCore() << endl
              << "显存是:" << AgxKits.GetMemory() << " G" << endl
              << "存储是:" << AgxKits.GetStorage() << " G" << endl;
}

const string &BinocularCamera::GetModel() const
{
    return model_;
}

void BinocularCamera::SetModel(const string &model)
{
    model_ = model;
}

const string &BinocularCamera::GetCamera() const
{
    return camera_;
}

void BinocularCamera::SetCamera(const string &camera)
{
    camera_ = camera;
}

const string &BinocularCamera::GetRgbFrameResolution() const
{
    return rgb_frame_resolution_;
}

void BinocularCamera::SetRgbFrameResolution(const string &rgb_frame_resolution)
{
    rgb_frame_resolution_ = rgb_frame_resolution;
}

double BinocularCamera::GetRgbFramRate() const
{
    return rgb_fram_rate_;
}

void BinocularCamera::SetRgbFramRate(double rgb_fram_rate)
{
    rgb_fram_rate_ = rgb_fram_rate;
}

const string &BinocularCamera::GetFov() const
{
    return fov_;
}

void BinocularCamera::SetFov(const string &fov)
{
    fov_ = fov;
}

double BinocularCamera::GetFrameRateOfDepth() const
{
    return frame_rate_of_depth_;
}

void BinocularCamera::SetFrameRateOfDepth(double frame_rate_of_depth)
{
    frame_rate_of_depth_ = frame_rate_of_depth;
}

void BinocularCamera::Print() const
{
    cout << *this << endl;
}

bool BinocularCamera::Save(const string &filename) const
{
    ofstream out(filename, ios::app);
    if (!out.is_open())
    {
        cout << "文件打开失败" << endl;
        return false;
    }
    out << *this << endl;
    out.close();
    return true;
}

ostream &operator<<(ostream &os, const BinocularCamera &binocularCamera)
{
    return os << "双目摄像机的型号是：" << binocularCamera.GetModel() << endl
              << "摄像头是：" << binocularCamera.GetCamera() << endl
              << "RGB帧分辨率是：" << binocularCamera.GetRgbFrameResolution() << endl
              << "RGB帧率是：" << binocularCamera.GetRgbFramRate() << endl
              << "FOV是：" << binocularCamera.GetFov() << endl
              << "深度帧率是：" << binocularCamera.GetFrameRateOfDepth() << endl;
}

const string &LiDar::GetModel() const
{
    return model_;
}

void LiDar::SetModel(const string &model)
{
    model_ = model;
}

double LiDar::GetChannelNumber() const
{
    return channel_number_;
}

void LiDar::SetChannelNumber(double channel_number)
{
    channel_number_ = channel_number;
}

double LiDar::GetTestScope() const
{
    return test_scope_;
}

void LiDar::SetTestScope(double test_scope)
{
    test_scope_ = test_scope;
}

double LiDar::GetPower() const
{
    return power_;
}

void LiDar::SetPower(double power)
{
    power_ = power;
}

void LiDar::Print() const
{
    cout << *this << endl;
}

bool LiDar::Save(const string &filename) const
{
    ofstream out(filename, ios::app);
    if (!out.is_open())
    {
        cout << "文件打开失败" << endl;
        return false;
    }
    out << *this << endl;
    out.close();
    return true;
}

ostream &operator<<(ostream &os, const LiDar &LiDar)
{
    return os << "激光雷达的型号是：" << LiDar.GetModel() << endl
              << "通道数是：" << LiDar.GetChannelNumber() << endl
              << "测试范围是：" << LiDar.GetTestScope() << " m" << endl
              << "功耗是：" << LiDar.GetPower() << " w" << endl;
}

const string &Gyroscope::GetModel() const
{
    return model_;
}

void Gyroscope::SetModel(const string &model)
{
    model_ = model;
}

const string &Gyroscope::GetBrand() const
{
    return brand_;
}

void Gyroscope::SetBrand(const string &brand)
{
    brand_ = brand;
}

void Gyroscope::Print() const
{
    cout << *this << endl;
}

bool Gyroscope::Save(const string &filename) const
{
    ofstream out(filename, ios::app);
    if (!out.is_open())
    {
        cout << "文件打开失败" << endl;
        return false;
    }
    out << *this << endl;
    out.close();
    return true;
}

ostream &operator<<(ostream &os, const Gyroscope &gyroscope)
{
    return os << "陀螺仪的型号是：" << gyroscope.GetModel() << endl
              << "厂商是：" << gyroscope.GetBrand() << endl;
}

const string &LcdScreen::GetModel() const
{
    return model_;
}

void LcdScreen::SetModel(const string &model)
{
    model_ = model;
}

double LcdScreen::GetSize() const
{
    return size_;
}

void LcdScreen::SetSize(double size)
{
    size_ = size;
}

void LcdScreen::Print() const
{
    cout << *this << endl;
}

bool LcdScreen::Save(const string &filename) const
{
    ofstream out(filename, ios::app);
    if (!out.is_open())
    {
        cout << "文件打开失败" << endl;
        return false;
    }
    out << *this << endl;
    out.close();
    return true;
}

ostream &operator<<(ostream &os, const LcdScreen &LcdScreen)
{
    return os << "液晶显示屏的型号是：" << LcdScreen.GetModel() << endl
              << "尺寸是：" << LcdScreen.GetSize() << endl;
}

const string &BatteryModule::GetParameter() const
{
    return parameter_;
}

void BatteryModule::SetParameter(const string &parameter)
{
    parameter_ = parameter;
}

double BatteryModule::GetExternalPowerSupply() const
{
    return external_power_supply_;
}

void BatteryModule::SetExternalPowerSupply(double external_power_supply)
{
    external_power_supply_ = external_power_supply;
}

double BatteryModule::GetChargeTime() const
{
    return charge_time_;
}

void BatteryModule::SetChargeTime(double charge_time)
{
    charge_time_ = charge_time;
}

void BatteryModule::Print() const
{
    cout << *this << endl;
}

bool BatteryModule::Save(const string &filename) const
{
    ofstream out(filename, ios::app);
    if (!out.is_open())
    {
        cout << "文件打开失败" << endl;
        return false;
    }
    out << *this << endl;
    out.close();
    return true;
}

ostream &operator<<(ostream &os, const BatteryModule &batteryModule)
{
    return os << "电池模组的参数是：" << batteryModule.GetParameter() << endl
              << "对外供电是：" << batteryModule.GetExternalPowerSupply() << " V" << endl
              << "充电时间是：" << batteryModule.GetChargeTime() << " H" << endl;
}

void SmartCar::Print() const
{
    cout << *this << endl;
}

bool SmartCar::Save(const string& filename) const
{
    ofstream out(filename, ios::app);
    if (!out.is_open())
    {
        cout << "文件打开失败" << endl;
        return false;
    }
    out << *this << endl;
    out.close();
    return true;
}

ostream &operator<<(ostream &os, const SmartCar &smartCar)
{
    return os << "智能小车的编号是：" << smartCar.id_ << endl
              << smartCar.underpan_ << endl
              << smartCar.agx_kits_ << endl
              << smartCar.binocular_camera_ << endl
              << smartCar.li_dar_ << endl
              << smartCar.gyroscope_ << endl
              << smartCar.lcd_screen_ << endl
              << smartCar.battery_module_ << endl;
}