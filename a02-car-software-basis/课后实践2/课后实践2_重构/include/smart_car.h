#ifndef SMART_CAR_H
#define SMART_CAR_H

#include <iostream>
#include <string>
#include "printable.h"
#include "saveable.h"

// 底盘
class Underpan : public Printable, public Saveable
{
private:
    // 编号：dp打头的8位数字+字母
    std::string id_;
    // 型号
    std::string model_;
    // 轴距
    double wheel_base_;
    // 轮距
    double axle_track_;
    // 最小离地间隙
    double ground_clearance_;
    // 最小转弯半径
    double minimum_bending_radius_;
    // 驱动形式
    std::string drive_form_;
    // 最大行程
    double battery_life_;
    // 轮胎型号
    std::string tire_model_;
    // 轮胎尺寸
    double tire_size_;

public:
    const std::string &GetId() const;

    void SetId(const std::string &);

    const std::string &GetModel() const;

    void SetModel(const std::string &);

    double GetWheelBase() const;

    void SetWheelBase(double);

    double GetAxleTrack() const;

    void SetAxleTrack(double);

    double GetGroundClearance() const;

    void SetGroundClearance(double);

    double GetMinimumBendingRadius() const;

    void SetMinimumBendingRadius(double);

    const std::string &GetDriveForm() const;

    void SetDriveForm(const std::string &);

    double GetBatteryLife() const;

    void SetBatteryLife(double);

    const std::string &GetTireModel() const;

    void SetTireModel(const std::string &);

    double GetTireSize() const;

    void SetTireSize(double);

    void Print() const override;

    bool Save(const std::string &) const override;

    friend std::ostream &operator<<(std::ostream &, const Underpan &);
};

// AGX套件
class AgxKits : public Printable, public Saveable
{
private:
    // 型号
    std::string model_;
    // AI
    double ai_hashrate_;
    // CUDA核心
    double cuda_core_num_;
    // Tensor CORE
    double tensor_core_;
    // 显存
    double memory_;
    // 外存
    double storage_;

public:
    const std::string &GetModel() const;

    void SetModel(const std::string &);

    double GetAiHashrate() const;

    void SetAiHashrate(double);

    double GetCudaCoreNum() const;

    void SetCudaCoreNum(double);

    double GetTensorCore() const;

    void SetTensorCore(double);

    double GetMemory() const;

    void SetMemory(double);

    double GetStorage() const;

    void SetStorage(double);

    void Print() const override;

    bool Save(const std::string &) const override;

    friend std::ostream &operator<<(std::ostream &, const AgxKits &);
};

// 双目摄像头
class BinocularCamera : public Printable, public Saveable
{
private:
    // 型号
    std::string model_;
    // 摄像头
    std::string camera_;
    // RGB帧分辨率
    std::string rgb_frame_resolution_;
    // RGB帧率
    double rgb_fram_rate_;
    // FOV
    std::string fov_;
    // 深度帧率
    double frame_rate_of_depth_;

public:
    const std::string &GetModel() const;

    void SetModel(const std::string &);

    const std::string &GetCamera() const;

    void SetCamera(const std::string &);

    const std::string &GetRgbFrameResolution() const;

    void SetRgbFrameResolution(const std::string &);

    double GetRgbFramRate() const;

    void SetRgbFramRate(double);

    const std::string &GetFov() const;

    void SetFov(const std::string &);

    double GetFrameRateOfDepth() const;

    void SetFrameRateOfDepth(double);

    void Print() const override;

    bool Save(const std::string &) const override;

    friend std::ostream &operator<<(std::ostream &, const BinocularCamera &);
};

// 多线激光雷达
class LiDar : public Printable, public Saveable
{
private:
    // 型号
    std::string model_;
    // 通道数
    double channel_number_;
    // 测试范围
    double test_scope_;
    // 功耗
    double power_;

public:
    const std::string &GetModel() const;

    void SetModel(const std::string &);

    double GetChannelNumber() const;

    void SetChannelNumber(double);

    double GetTestScope() const;

    void SetTestScope(double);

    double GetPower() const;

    void SetPower(double);

    void Print() const override;

    bool Save(const std::string &) const override;

    friend std::ostream &operator<<(std::ostream &, const LiDar &);
};

// 9轴陀螺仪
class Gyroscope : public Printable, public Saveable
{
private:
    // 型号
    std::string model_;
    // 厂家
    std::string brand_;

public:
    const std::string &GetModel() const;

    void SetModel(const std::string &);

    const std::string &GetBrand() const;

    void SetBrand(const std::string &);

    void Print() const override;

    bool Save(const std::string &) const override;

    friend std::ostream &operator<<(std::ostream &, const Gyroscope &);
};

// 液晶显示屏
class LcdScreen : public Printable, public Saveable
{
private:
    // 型号
    std::string model_;
    // 尺寸
    double size_;

public:
    const std::string &GetModel() const;

    void SetModel(const std::string &);

    double GetSize() const;

    void SetSize(double);

    void Print() const override;

    bool Save(const std::string &) const override;

    friend std::ostream &operator<<(std::ostream &, const LcdScreen &);
};

// 电池模块
class BatteryModule : public Printable, public Saveable
{
private:
    // 参数
    std::string parameter_;
    // 对外供电
    double external_power_supply_;
    // 充电时间
    double charge_time_;

public:
    const std::string &GetParameter() const;

    void SetParameter(const std::string &);

    double GetExternalPowerSupply() const;

    void SetExternalPowerSupply(double);

    double GetChargeTime() const;

    void SetChargeTime(double);

    void Print() const override;

    bool Save(const std::string &) const override;

    friend std::ostream &operator<<(std::ostream &, const BatteryModule &);
};

// 智能小车
class SmartCar : public Printable, public Saveable
{
public:
    // 自定义，cqusn打头的16位数字+字母
    std::string id_;
    // 底座
    Underpan underpan_;
    // 套件
    AgxKits agx_kits_;
    // 双目摄像头
    BinocularCamera binocular_camera_;
    // 多线激光雷达
    LiDar li_dar_;
    // 9轴陀螺仪
    Gyroscope gyroscope_;
    // 液晶显示屏
    LcdScreen lcd_screen_;
    // 电池模块
    BatteryModule battery_module_;

    void Print() const override;

    bool Save(const std::string &) const override;

    friend std::ostream &operator<<(std::ostream &, const SmartCar &);
};

#endif