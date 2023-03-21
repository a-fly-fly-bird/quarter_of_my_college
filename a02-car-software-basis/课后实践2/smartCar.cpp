/*
 * 车载软件开发基础 demo 1
 * author: 谭勇
 * date: 2022/10/1
 * keymap: collapse all: command + shift + - (+)
 */

#include "smartCar.h"
#include <ctime>
#include <iostream>
#include <unistd.h>
#include <string>
#include <limits>
#include <map>
#include <fstream>

using namespace std;

// global var
int purchaseAmount = 0;
int availableAmount = 0;
int studentAmount = 0;
map<string, BindInfo *> bindMap;

bool saveMap(string filename)
{
    formatDivision("开始保存数据到文件", '*', 100);
    fileEmpty(filename);
    ofstream of;
    of.open(filename, ios::app);
    of << purchaseAmount - availableAmount << endl;
    of.close();
    map<string, BindInfo *>::iterator iter;
    iter = bindMap.begin();
    while (iter != bindMap.end())
    {
        // of.open(filename, ios::app);
        // of << iter->first << endl;
        // of.close();
        iter->second->save(filename);
        // << *iter->second << endl;
        iter++;
    }

    formatDivision("保存成功", '*', 100);
}

bool readInfoFromFile(string filename)
{
    formatDivision("开始读取文件中的数据", '*', 100);
    string input;
    const int LINES_PER_DATA = 48;
    int now_data = 0;
    ifstream infile;
    infile.open(filename);
    string num_s;
    getline(infile, num_s);
    int num = stoi(num_s);
    while (input != "exit")
    {
        cout << "请输入指令：" << endl;
        cin >> input;
        cin.get();
        if (input == "n")
        {
            if (now_data < num)
            {
                ++now_data;
                cout << "第" << now_data << "个数据是：\n"
                     << endl;
                cout << readInfoFromFileLineM2N(filename, (now_data - 1) * LINES_PER_DATA + 2,
                                                now_data * LINES_PER_DATA + 2);
            }
            else
            {
                cout << "已经是最后一个数据了。" << endl;
            }
        }
        else if (input == "p")
        {
            if (now_data > 1)
            {
                --now_data;
                cout << "第" << now_data << "个数据是：\n"
                     << endl;
                cout << readInfoFromFileLineM2N(filename, (now_data - 1) * LINES_PER_DATA + 2,
                                                now_data * LINES_PER_DATA + 2);
            }
            else
            {
                cout << "已经是第一个数据了。" << endl;
            }
        }
        else
        {
            cout << "退出输入：exit" << endl;
            continue;
        }
    }
    formatDivision("读取完毕", '*', 100);
}

BindInfo *getBindInfo(const string &stuId)
{
    auto iter = bindMap.find(stuId);
    if (iter != bindMap.end())
    {
        formatDivision("绑定信息", '*', 100);
        cout << *iter->second << endl;
        return iter->second;
    }
    else
    {
        cout << "没有该学生信息。\n"
             << endl;
        return nullptr;
    }
}

bool mapBind(BindInfo *bindInfos)
{
    for (int i = 0; i < studentAmount; ++i)
    {
        if (bindMap.find(bindInfos[i].getStudent()->getId()) == bindMap.end())
        {
            bindMap.insert(pair<string, BindInfo *>(bindInfos[i].getStudent()->getId(), &bindInfos[i]));
        }
        else
        {
            availableAmount += 1;
            cout << "该学生已经存在绑定信息，请更换绑定。" << endl;
        }
    }
    return true;
}

bool bind(Student *students, SmartCar *smartCars, BindInfo *bindInfos)
{
    for (int i = purchaseAmount - availableAmount; i < purchaseAmount - availableAmount + studentAmount; ++i)
    {
        bindInfos[i].setStudent(&students[i]);
        bindInfos[i].setSmartCar(&smartCars[i]);
        cout << "绑定信息是：" << endl
             << bindInfos[i] << endl;
    }
    availableAmount -= studentAmount;
    formatDivision("绑定完成", '*', 100);
    return true;
}

Student *inputStudents()
{
    // https://stackoverflow.com/questions/17335816/clear-screen-using-c
    // clear screen in linux or windows
    cout << "\033[2J\033[1;1H";
    cout << "请输入需要小车的人数：";
    cin >> studentAmount;
    studentAmount = checkInputRange(studentAmount, 0, "输入不是正数，或者超出了可用的小车的范围。请重新输入：", availableAmount);
    auto *students = new Student[studentAmount];
    for (int i = 0; i < studentAmount; ++i)
    {
        students[i].setId(stringInputInformationHelper("学号"));
        students[i].setName(stringInputInformationHelper("姓名"));
        formatDivision("第" + to_string(i + 1) + " 个学生的数据是:", '*', 100);
        cout << students[i] << endl;
    }
    formatDivision("信息录入完成", '*', 100);
    return students;
}

SmartCar *inputInformation()
{
    cout << "请输入采购的小车数量：";
    string input;
    cin >> input;
    purchaseAmount = checkIfNum(input);
    purchaseAmount = checkInputRange(purchaseAmount, 0, "数量不合法, 请重新输入采购的小车数量:");
    cout << "你采购的小车数是：" << purchaseAmount << endl;
    auto *smartCars = new SmartCar[purchaseAmount];
    string underpan[] = {"型号", "轴距(mm)", "轮距(mm)", "最小离地间隙(mm)", "最小转弯半径(m)", "驱动形式",
                         "最大行程(km)", "轮胎型号", "轮胎尺寸(mm)"};
    for (int i = 0; i < purchaseAmount; ++i)
    {
        // 随机数生成
        srand((unsigned)time(NULL) * getpid());
        string random_gen = gen_random(11);
        smartCars[i].id = "cqusn" + random_gen;
        // 底盘
        srand((unsigned)time(NULL) * getpid());
        random_gen = gen_random(6);
        smartCars[i].underpan.setId("dp" + random_gen);
        smartCars[i].underpan.setModel(stringInputInformationHelper(underpan[0]));
        smartCars[i].underpan.setWheelBase(doubleInputInformationHelper(underpan[1], 0.0, "轴距输入范围错误"));
        smartCars[i].underpan.setAxleTrack(doubleInputInformationHelper(underpan[2], 0.0, "轮距输入范围错误"));
        // smartCars[i].underpan.setGroundClearance(doubleInputInformationHelper(underpan[3], 0.0, "最小离地间隙输入范围错误"));
        // smartCars[i].underpan.setMinimumBendingRadius(doubleInputInformationHelper(underpan[4], 0.0, "最小转弯半径输入范围错误"));
        // smartCars[i].underpan.setDriveForm(stringInputInformationHelper(underpan[5]));
        // smartCars[i].underpan.setBatteryLife(doubleInputInformationHelper(underpan[6], 0.0, "最大行程输入范围错误"));
        // smartCars[i].underpan.setTireModel(stringInputInformationHelper(underpan[7]));
        // smartCars[i].underpan.setTireSize(doubleInputInformationHelper(underpan[8], 0.0, "轮胎尺寸输入有误"));
        // // AGXKits
        // smartCars[i].aGXKits.setModel(stringInputInformationHelper("型号"));
        // smartCars[i].aGXKits.setAiHashrate(doubleInputInformationHelper("AI(TOPS)"));
        // smartCars[i].aGXKits.setCudaCoreNum(doubleInputInformationHelper("CUDA核心"));
        // smartCars[i].aGXKits.setTensorCore(doubleInputInformationHelper("Tensor CORE"));
        // smartCars[i].aGXKits.setMemory(doubleInputInformationHelper("显存(G)"));
        // smartCars[i].aGXKits.setStorage(doubleInputInformationHelper("存储(G)"));
        // // 双目摄像头
        // smartCars[i].binocularCamera.setModel(stringInputInformationHelper("型号"));
        // smartCars[i].binocularCamera.setCamera(stringInputInformationHelper("摄像头"));
        // smartCars[i].binocularCamera.setRgbFrameResolution(stringInputInformationHelper("RGB帧分辨率"));
        // smartCars[i].binocularCamera.setRgbFramRate(doubleInputInformationHelper("RGB帧率", 0.0));
        // smartCars[i].binocularCamera.setFov(stringInputInformationHelper("FOV"));
        // smartCars[i].binocularCamera.setFrameRateOfDepth(doubleInputInformationHelper("深度帧率", 0.0));
        // // 多线激光雷达
        // smartCars[i].liDAR.setModel(stringInputInformationHelper("型号"));
        // smartCars[i].liDAR.setChannelNumber(doubleInputInformationHelper("通道数", 0.0));
        // smartCars[i].liDAR.setTestScope(doubleInputInformationHelper("测试范围(m)", 0.0));
        // smartCars[i].liDAR.setPower(doubleInputInformationHelper("功耗(w)", 0.0));
        // // 9轴陀螺仪
        // smartCars[i].gyroscope.setModel(stringInputInformationHelper("型号"));
        // smartCars[i].gyroscope.setBrand(stringInputInformationHelper("厂商"));
        // // 液晶显示屏
        // smartCars[i].lcd.setModel(stringInputInformationHelper("型号"));
        // smartCars[i].lcd.setSize(doubleInputInformationHelper("尺寸", 0.0));
        // // 电池模块
        // smartCars[i].batteryModule.setParameter(stringInputInformationHelper("参数"));
        // smartCars[i].batteryModule.setExternalPowerSupply(doubleInputInformationHelper("对外供电(V)", 0.0));
        // smartCars[i].batteryModule.setChargeTime(doubleInputInformationHelper("充电时间(H)", 0.0));

        formatDivision("\n第 " + to_string(i + 1) + " 个小车的数据是", '*', 100);
        smartCars[i].print();
    }
    availableAmount = purchaseAmount;
    formatDivision("小车信息录入完成", '*', 100);
    return smartCars;
}


// ----------------------------------------------------------------------------------------------------------------------------------

void fileEmpty(string fileName)
{
    fstream file(fileName, ios::out);
    return;
}

string readInfoFromFileLineM2N(const string &filename, int begin, int end)
{
    string rawLine;
    string content;
    ifstream infile;
    infile.open(filename);
    for (int i = 0; i < begin;)
    {
        if (infile.get() == '\n')
            i++;
    }
    for (int i = begin; i < end; ++i)
    {
        getline(infile, rawLine);
        content += rawLine + "\n";
    }
    infile.close();
    return content;
}

// 检查数字是否超出范围
template <class T>
T checkInputRange(T input, T min, string errorMsg, T max)
{
    if (input > max || input < min)
    {
        cout << errorMsg;
        cin >> input;
        input = checkInputRange(input, min, errorMsg, max);
    }
    return input;
}

int checkIfNum(string input)
{
    int res;
    try
    {
        res = stoi(input);
    }
    catch (exception e)
    {
        cout << "输入的不是数字,请重新输入: ";
        cin >> input;
        res = checkIfNum(input);
    }
    return res;
}

string stringInputInformationHelper(const string &requestInfo)
{
    cout << "请输入" << requestInfo << "信息：";
    string info;
    cin >> info;
    return info;
}

double doubleInputInformationHelper(const string &requestInfo, double min, const string &errorMsg, double max)
{
    cout << "请输入" << requestInfo << "信息：";
    string info;
    double res;
    cin >> info;
    // check if double
    try
    {
        res = stod(info);
    }
    catch (const exception &)
    {
        cout << "输入的不是数字，请重新输入。" << endl;
        res = doubleInputInformationHelper(requestInfo, min, errorMsg, max);
    }
    res = checkInputRange(res, min, errorMsg, max);
    return res;
}

string gen_random(const int len)
{
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i)
    {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return tmp_s;
}

void formatDivision(const string &info, char divisionChar, int numOfDivChar)
{
    int len = info.length();
    int halfNumOfDiv = (numOfDivChar - len - 2) / 2;
    for (int i = 0; i < halfNumOfDiv; ++i)
    {
        cout << divisionChar;
    }
    cout << " " << info << " ";
    for (int i = 0; i < halfNumOfDiv; ++i)
    {
        cout << divisionChar;
    }
    cout << endl;
}

const string &Student::getId() const
{
    return id;
}

void Student::setId(const string &id)
{
    Student::id = id;
}

const string &Student::getName() const
{
    return name;
}

void Student::setName(const string &name)
{
    Student::name = name;
}

void Student::print()
{
    cout << *this << endl;
}

bool Student::save(string filename)
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

const string &Underpan::getId() const
{
    return id;
}

void Underpan::setId(const string &id)
{
    Underpan::id = id;
}

const string &Underpan::getModel() const
{
    return model;
}

void Underpan::setModel(const string &model)
{
    Underpan::model = model;
}

double Underpan::getWheelBase() const
{
    return wheelBase;
}

void Underpan::setWheelBase(double wheelBase)
{
    Underpan::wheelBase = wheelBase;
}

double Underpan::getAxleTrack() const
{
    return AxleTrack;
}

void Underpan::setAxleTrack(double axleTrack)
{
    AxleTrack = axleTrack;
}

double Underpan::getGroundClearance() const
{
    return groundClearance;
}

void Underpan::setGroundClearance(double groundClearance)
{
    Underpan::groundClearance = groundClearance;
}

double Underpan::getMinimumBendingRadius() const
{
    return minimumBendingRadius;
}

void Underpan::setMinimumBendingRadius(double minimumBendingRadius)
{
    Underpan::minimumBendingRadius = minimumBendingRadius;
}

const string &Underpan::getDriveForm() const
{
    return driveForm;
}

void Underpan::setDriveForm(const string &driveForm)
{
    Underpan::driveForm = driveForm;
}

double Underpan::getBatteryLife() const
{
    return batteryLife;
}

void Underpan::setBatteryLife(double batteryLife)
{
    Underpan::batteryLife = batteryLife;
}

const string &Underpan::getTireModel() const
{
    return tireModel;
}

void Underpan::setTireModel(const string &tireModel)
{
    Underpan::tireModel = tireModel;
}

double Underpan::getTireSize() const
{
    return tireSize;
}

void Underpan::setTireSize(double tireSize)
{
    Underpan::tireSize = tireSize;
}

void Underpan::print()
{
    cout << *this << endl;
}

bool Underpan::save(string filename)
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

const string &AGXKits::getModel() const
{
    return model;
}

void AGXKits::setModel(const string &model)
{
    AGXKits::model = model;
}

double AGXKits::getAiHashrate() const
{
    return AIHashrate;
}

void AGXKits::setAiHashrate(double aiHashrate)
{
    AIHashrate = aiHashrate;
}

double AGXKits::getCudaCoreNum() const
{
    return CUDACoreNum;
}

void AGXKits::setCudaCoreNum(double cudaCoreNum)
{
    CUDACoreNum = cudaCoreNum;
}

double AGXKits::getTensorCore() const
{
    return tensorCORE;
}

void AGXKits::setTensorCore(double tensorCore)
{
    tensorCORE = tensorCore;
}

double AGXKits::getMemory() const
{
    return memory;
}

void AGXKits::setMemory(double memory)
{
    AGXKits::memory = memory;
}

double AGXKits::getStorage() const
{
    return storage;
}

void AGXKits::setStorage(double storage)
{
    AGXKits::storage = storage;
}

void AGXKits::print()
{
    cout << *this << endl;
}

bool AGXKits::save(string filename)
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

const string &BinocularCamera::getModel() const
{
    return model;
}

void BinocularCamera::setModel(const string &model)
{
    BinocularCamera::model = model;
}

const string &BinocularCamera::getCamera() const
{
    return camera;
}

void BinocularCamera::setCamera(const string &camera)
{
    BinocularCamera::camera = camera;
}

const string &BinocularCamera::getRgbFrameResolution() const
{
    return RGBFrameResolution;
}

void BinocularCamera::setRgbFrameResolution(const string &rgbFrameResolution)
{
    RGBFrameResolution = rgbFrameResolution;
}

double BinocularCamera::getRgbFramRate() const
{
    return RGBFramRate;
}

void BinocularCamera::setRgbFramRate(double rgbFramRate)
{
    RGBFramRate = rgbFramRate;
}

const string &BinocularCamera::getFov() const
{
    return FOV;
}

void BinocularCamera::setFov(const string &fov)
{
    FOV = fov;
}

double BinocularCamera::getFrameRateOfDepth() const
{
    return frameRateOfDepth;
}

void BinocularCamera::setFrameRateOfDepth(double frameRateOfDepth)
{
    BinocularCamera::frameRateOfDepth = frameRateOfDepth;
}

void BinocularCamera::print()
{
    cout << *this << endl;
}

bool BinocularCamera::save(string filename)
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

const string &LiDAR::getModel() const
{
    return model;
}

void LiDAR::setModel(const string &model)
{
    LiDAR::model = model;
}

double LiDAR::getChannelNumber() const
{
    return channelNumber;
}

void LiDAR::setChannelNumber(double channelNumber)
{
    LiDAR::channelNumber = channelNumber;
}

double LiDAR::getTestScope() const
{
    return testScope;
}

void LiDAR::setTestScope(double testScope)
{
    LiDAR::testScope = testScope;
}

double LiDAR::getPower() const
{
    return power;
}

void LiDAR::setPower(double power)
{
    LiDAR::power = power;
}

void LiDAR::print()
{
    cout << *this << endl;
}

bool LiDAR::save(string filename)
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

const string &Gyroscope::getModel() const
{
    return model;
}

void Gyroscope::setModel(const string &model)
{
    Gyroscope::model = model;
}

const string &Gyroscope::getBrand() const
{
    return brand;
}

void Gyroscope::setBrand(const string &brand)
{
    Gyroscope::brand = brand;
}

void Gyroscope::print()
{
    cout << *this << endl;
}

bool Gyroscope::save(string filename)
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

const string &LCD::getModel() const
{
    return model;
}

void LCD::setModel(const string &model)
{
    LCD::model = model;
}

double LCD::getSize() const
{
    return size;
}

void LCD::setSize(double size)
{
    LCD::size = size;
}

void LCD::print()
{
    cout << *this << endl;
}

bool LCD::save(string filename)
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

const string &BatteryModule::getParameter() const
{
    return parameter;
}

void BatteryModule::setParameter(const string &parameter)
{
    BatteryModule::parameter = parameter;
}

double BatteryModule::getExternalPowerSupply() const
{
    return externalPowerSupply;
}

void BatteryModule::setExternalPowerSupply(double externalPowerSupply)
{
    BatteryModule::externalPowerSupply = externalPowerSupply;
}

double BatteryModule::getChargeTime() const
{
    return chargeTime;
}

void BatteryModule::setChargeTime(double chargeTime)
{
    BatteryModule::chargeTime = chargeTime;
}

void BatteryModule::print()
{
    cout << *this << endl;
}

bool BatteryModule::save(string filename)
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

Student *BindInfo::getStudent() const
{
    return student;
}

void BindInfo::setStudent(Student *student)
{
    BindInfo::student = student;
}

SmartCar *BindInfo::getSmartCar() const
{
    return smartCar;
}

void BindInfo::setSmartCar(SmartCar *smartCar)
{
    BindInfo::smartCar = smartCar;
}

void BindInfo::print()
{
    cout << *this << endl;
}

bool BindInfo::save(string filename)
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

void SmartCar::print()
{
    cout << *this << endl;
}

bool SmartCar::save(string filename)
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

ostream &operator<<(ostream &os, const Student &student)
{
    return os << "学生的编号是：" << student.getId() << endl
              << "姓名是：" << student.getName() << endl;
}

ostream &operator<<(ostream &os, const Underpan &underpan)
{
    return os << "底盘的编号是：" << underpan.getId() << endl
              << "型号是：" << underpan.getModel() << endl
              << "轴距是: " << underpan.getWheelBase() << " mm" << endl
              << "轮距是: " << underpan.getAxleTrack() << " mm" << endl
              << "最小离地间隙是：" << underpan.getGroundClearance() << " mm" << endl
              << "最小转弯半径是：" << underpan.getMinimumBendingRadius() << " m" << endl
              << "驱动形式是：" << underpan.getDriveForm() << endl
              << "最大行程是：" << underpan.getBatteryLife() << " km" << endl
              << "轮胎型号是：" << underpan.getTireModel() << endl
              << "轮胎尺寸是：" << underpan.getTireSize() << " mm" << endl;
}

ostream &operator<<(ostream &os, const AGXKits &aGXKits)
{
    return os << "AGX组件的型号是：" << aGXKits.getModel() << endl
              << "AI是：" << aGXKits.getAiHashrate() << " TOPS" << endl
              << "CUDA核心是：" << aGXKits.getCudaCoreNum() << endl
              << "Tensor CORE是：" << aGXKits.getTensorCore() << endl
              << "显存是：" << aGXKits.getMemory() << " G" << endl
              << "存储是：" << aGXKits.getStorage() << " G" << endl;
}

ostream &operator<<(ostream &os, const BinocularCamera &binocularCamera)
{
    return os << "双目摄像机的型号是：" << binocularCamera.getModel() << endl
              << "摄像头是：" << binocularCamera.getCamera() << endl
              << "RGB帧分辨率是：" << binocularCamera.getRgbFrameResolution() << endl
              << "RGB帧率是：" << binocularCamera.getRgbFramRate() << endl
              << "FOV是：" << binocularCamera.getFov() << endl
              << "深度帧率是：" << binocularCamera.getFrameRateOfDepth() << endl;
}

ostream &operator<<(ostream &os, const LiDAR &liDAR)
{
    return os << "激光雷达的型号是：" << liDAR.getModel() << endl
              << "通道数是：" << liDAR.getChannelNumber() << endl
              << "测试范围是：" << liDAR.getTestScope() << " m" << endl
              << "功耗是：" << liDAR.getPower() << " w" << endl;
}

ostream &operator<<(ostream &os, const Gyroscope &gyroscope)
{
    return os << "陀螺仪的型号是：" << gyroscope.getModel() << endl
              << "厂商是：" << gyroscope.getBrand() << endl;
}

ostream &operator<<(ostream &os, const LCD &lcd)
{
    return os << "液晶显示屏的型号是：" << lcd.getModel() << endl
              << "尺寸是：" << lcd.getSize() << endl;
}

ostream &operator<<(ostream &os, const BatteryModule &batteryModule)
{
    return os << "电池模组的参数是：" << batteryModule.getParameter() << endl
              << "对外供电是：" << batteryModule.getExternalPowerSupply() << " V" << endl
              << "充电时间是：" << batteryModule.getChargeTime() << " H" << endl;
}

ostream &operator<<(ostream &os, const SmartCar &smartCar)
{
    return os << "智能小车的编号是：" << smartCar.id << endl
              << smartCar.underpan << endl
              << smartCar.aGXKits << endl
              << smartCar.binocularCamera << endl
              << smartCar.liDAR << endl
              << smartCar.gyroscope << endl
              << smartCar.lcd << endl
              << smartCar.batteryModule << endl;
}

ostream &operator<<(ostream &os, const BindInfo &bindInfo)
{
    return os << "绑定的学生信息是：\n"
              << *bindInfo.getStudent() << endl
              << "绑定的智能汽车信息是：\n"
              << *bindInfo.getSmartCar() << endl;
}