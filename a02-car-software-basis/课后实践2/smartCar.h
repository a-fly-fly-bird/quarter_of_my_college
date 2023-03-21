/*
 * 车载软件开发基础 demo 1
 * author: 谭勇
 * date: 2022/10/1
 */

#ifndef HOMEWORK_1_SMARTCAR_H
#define HOMEWORK_1_SMARTCAR_H

#include <string>

using namespace std;

extern int purchaseAmount;

// 学生信息
class Student
{
private:
    // 学号
    string id;
    // 姓名
    string name;

public:
    const string &getId() const;

    void setId(const string &id);

    const string &getName() const;

    void setName(const string &name);

    void print();

    bool save(string filename);
};

// 底盘
class Underpan
{
private:
    // 编号：dp打头的8位数字+字母
    string id;
    // 型号
    string model;
    // 轴距
    double wheelBase;
    // 轮距
    double AxleTrack;
    // 最小离地间隙
    double groundClearance;
    // 最小转弯半径
    double minimumBendingRadius;
    // 驱动形式
    string driveForm;
    // 最大行程
    double batteryLife;
    // 轮胎型号
    string tireModel;
    // 轮胎尺寸
    double tireSize;

public:
    const string &getId() const;

    void setId(const string &id);

    const string &getModel() const;

    void setModel(const string &model);

    double getWheelBase() const;

    void setWheelBase(double wheelBase);

    double getAxleTrack() const;

    void setAxleTrack(double axleTrack);

    double getGroundClearance() const;

    void setGroundClearance(double groundClearance);

    double getMinimumBendingRadius() const;

    void setMinimumBendingRadius(double minimumBendingRadius);

    const string &getDriveForm() const;

    void setDriveForm(const string &driveForm);

    double getBatteryLife() const;

    void setBatteryLife(double batteryLife);

    const string &getTireModel() const;

    void setTireModel(const string &tireModel);

    double getTireSize() const;

    void setTireSize(double tireSize);

    void print();

    bool save(string filename);
};

// AGX套件
class AGXKits
{
private:
    // 型号
    string model;
    // AI
    double AIHashrate;
    // CUDA核心
    double CUDACoreNum;
    // Tensor CORE
    double tensorCORE;
    // 显存
    double memory;
    // 外存
    double storage;

public:
    const string &getModel() const;

    void setModel(const string &model);

    double getAiHashrate() const;

    void setAiHashrate(double aiHashrate);

    double getCudaCoreNum() const;

    void setCudaCoreNum(double cudaCoreNum);

    double getTensorCore() const;

    void setTensorCore(double tensorCore);

    double getMemory() const;

    void setMemory(double memory);

    double getStorage() const;

    void setStorage(double storage);

    void print();

    bool save(string filename);
};

// 双目摄像头
class BinocularCamera
{
private:
    // 型号
    string model;
    // 摄像头
    string camera;
    // RGB帧分辨率
    string RGBFrameResolution;
    // RGB帧率
    double RGBFramRate;
    // FOV
    string FOV;
    // 深度帧率
    double frameRateOfDepth;

public:
    const string &getModel() const;

    void setModel(const string &model);

    const string &getCamera() const;

    void setCamera(const string &camera);

    const string &getRgbFrameResolution() const;

    void setRgbFrameResolution(const string &rgbFrameResolution);

    double getRgbFramRate() const;

    void setRgbFramRate(double rgbFramRate);

    const string &getFov() const;

    void setFov(const string &fov);

    double getFrameRateOfDepth() const;

    void setFrameRateOfDepth(double frameRateOfDepth);

    void print();

    bool save(string filename);
};

// 多线激光雷达
class LiDAR
{
private:
    // 型号
    string model;
    // 通道数
    double channelNumber;
    // 测试范围
    double testScope;
    // 功耗
    double power;

public:
    const string &getModel() const;

    void setModel(const string &model);

    double getChannelNumber() const;

    void setChannelNumber(double channelNumber);

    double getTestScope() const;

    void setTestScope(double testScope);

    double getPower() const;

    void setPower(double power);

    void print();

    bool save(string filename);
};

// 9轴陀螺仪
class Gyroscope
{
private:
    // 型号
    string model;
    // 厂家
    string brand;

public:
    const string &getModel() const;

    void setModel(const string &model);

    const string &getBrand() const;

    void setBrand(const string &brand);

    void print();

    bool save(string filename);
};

// 液晶显示屏
class LCD
{
private:
    // 型号
    string model;
    // 尺寸
    double size;

public:
    const string &getModel() const;

    void setModel(const string &model);

    double getSize() const;

    void setSize(double size);

    void print();

    bool save(string filename);
};

// 电池模块
class BatteryModule
{
private:
    // 参数
    string parameter;
    // 对外供电
    double externalPowerSupply;
    // 充电时间
    double chargeTime;

public:
    const string &getParameter() const;

    void setParameter(const string &parameter);

    double getExternalPowerSupply() const;

    void setExternalPowerSupply(double externalPowerSupply);

    double getChargeTime() const;

    void setChargeTime(double chargeTime);

    void print();

    bool save(string filename);
};

// 智能小车
class SmartCar
{
public:
    // 自定义，cqusn打头的16位数字+字母
    string id;
    // 底座
    Underpan underpan;
    // 套件
    AGXKits aGXKits;
    // 双目摄像头
    BinocularCamera binocularCamera;
    // 多线激光雷达
    LiDAR liDAR;
    // 9轴陀螺仪
    Gyroscope gyroscope;
    // 液晶显示屏
    LCD lcd;
    // 电池模块
    BatteryModule batteryModule;

    void print();

    bool save(string filename);
};

class BindInfo
{
private:
    Student *student;
    SmartCar *smartCar;

public:
    Student *getStudent() const;

    void setStudent(Student *student);

    SmartCar *getSmartCar() const;

    void setSmartCar(SmartCar *smartCar);

    void print();

    bool save(string filename);
};

ostream &operator<<(ostream &, const Student &);

ostream &operator<<(ostream &, const Underpan &);

ostream &operator<<(ostream &, const AGXKits &);

ostream &operator<<(ostream &, const BinocularCamera &);

ostream &operator<<(ostream &, const LiDAR &);

ostream &operator<<(ostream &, const Gyroscope &);

ostream &operator<<(ostream &, const LCD &);

ostream &operator<<(ostream &, const BatteryModule &);

ostream &operator<<(ostream &, const SmartCar &);

ostream &operator<<(ostream &, const BindInfo &);

SmartCar *inputInformation();

string stringInputInformationHelper(const string &);

string gen_random(int);

Student *inputStudents();

bool bind(Student *, SmartCar *, BindInfo *);

bool mapBind(BindInfo *);

BindInfo *getBindInfo(const string &);

bool saveMap(string);

bool readInfoFromFile(string);

int checkIfNum(string input);

string readInfoFromFileLineM2N(const string &, int, int);

void formatDivision(const string &, char, int);

double doubleInputInformationHelper(const string &requestInfo, double min = numeric_limits<double>::min(),
                                    const string &errorMsg = "信息输入超出规定范围",
                                    double max = numeric_limits<double>::max());

template <class T>
// 默认参数不能在声明和定义中同时出现，所以最好在声明中出现。
T checkInputRange(T input, T min = numeric_limits<T>::min(), string errorMsg = "输入超出规定范围",
                  T max = numeric_limits<T>::max());

#endif // HOMEWORK_1_SMARTCAR_H
