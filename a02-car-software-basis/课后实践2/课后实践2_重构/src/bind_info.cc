#include <fstream>
#include <unistd.h>
#include "smart_car.h"
#include "student.h"
#include "bind_info.h"
#include "helper_function.h"

using namespace std;

Student *BindInfo::GetStudent() const
{
    return student_;
}

void BindInfo::SetStudent(Student *student)
{
    student_ = student;
}

SmartCar *BindInfo::GetSmartCar() const
{
    return smart_car_;
}

void BindInfo::SetSmartCar(SmartCar *smart_car)
{
    smart_car_ = smart_car;
}

void BindInfo::Print() const
{
    cout << *this << endl;
}

bool BindInfo::Save(const string &filename) const
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

ostream &operator<<(ostream &os, const BindInfo &bind_info)
{
    return os << "绑定的学生信息是：\n"
              << *bind_info.GetStudent() << endl
              << "绑定的智能汽车信息是：\n"
              << *bind_info.GetSmartCar() << endl;
}

bool SaveMap(string filename)
{
    FormatDivision("开始保存数据到文件", '*', 100);
    fileEmpty(filename);
    ofstream of;
    of.open(filename, ios::app);
    of << kPurchaseAmount - kAvailableAmount << endl;
    of.close();
    cout << "有" << kBindMap.size() << "个数据。" << endl;
    map<string, BindInfo *>::iterator iter;
    iter = kBindMap.begin();
    while (iter != kBindMap.end())
    {
        // of.open(filename, ios::app);
        // of << iter->first << endl;
        // of.close();
        iter->second->Save(filename);
        // << *iter->second << endl;
        iter++;
    }

    FormatDivision("保存成功", '*', 100);
}

bool ReadInfoFromFile(string filename)
{
    FormatDivision("开始读取文件中的数据", '*', 100);
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
    FormatDivision("读取完毕", '*', 100);
}

BindInfo *GetBindInfo(const string &stu_id)
{
    auto iter = kBindMap.find(stu_id);
    if (iter != kBindMap.end())
    {
        FormatDivision("绑定信息", '*', 100);
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

bool MapBind(BindInfo *bind_infos)
{
    for (int i = 0; i < kStudentAmount; ++i)
    {
        if (kBindMap.find(bind_infos[i].GetStudent()->GetId()) == kBindMap.end())
        {
            kBindMap.insert(pair<string, BindInfo *>(bind_infos[i].GetStudent()->GetId(), &bind_infos[i]));
        }
        else
        {
            kAvailableAmount += 1;
            cout << "该学生已经存在绑定信息，请更换绑定。" << endl;
        }
    }
    return true;
}

bool Bind(Student *students, SmartCar *smartCars, BindInfo *bind_infos)
{
    for (int i = kPurchaseAmount - kAvailableAmount; i < kPurchaseAmount - kAvailableAmount + kStudentAmount; ++i)
    {
        bind_infos[i].SetStudent(&students[i]);
        bind_infos[i].SetSmartCar(&smartCars[i]);
        cout << "绑定信息是：" << endl
             << bind_infos[i] << endl;
    }
    kAvailableAmount -= kStudentAmount;
    FormatDivision("绑定完成", '*', 100);
    return true;
}

Student *InputStudents()
{
    // https://stackoverflow.com/questions/17335816/clear-screen-using-c
    // clear screen in linux or windows
    cout << "\033[2J\033[1;1H";
    cout << "请输入需要小车的人数：";
    cin >> kStudentAmount;
    string info = "输入不是正数，或者超出了可用的小车的范围。请重新输入：";
    kStudentAmount = CheckInputRange(kStudentAmount, 0, info, kAvailableAmount);
    auto *students = new Student[kStudentAmount];
    for (int i = 0; i < kStudentAmount; ++i)
    {
        students[i].SetId(StringInputInformationHelper("学号"));
        students[i].SetName(StringInputInformationHelper("姓名"));
        FormatDivision("第" + to_string(i + 1) + " 个学生的数据是:", '*', 100);
        cout << students[i] << endl;
    }
    FormatDivision("信息录入完成", '*', 100);
    return students;
}

SmartCar *InputInformation()
{
    cout << "请输入采购的小车数量：";
    string input;
    cin >> input;
    kPurchaseAmount = CheckIfNum(input);
    string error_info = "数量不合法, 请重新输入采购的小车数量:";
    kPurchaseAmount = CheckInputRange(kPurchaseAmount, 0, error_info, 10000);
    cout << "你采购的小车数是：" << kPurchaseAmount << endl;
    auto *smartCars = new SmartCar[kPurchaseAmount];
    string underpan[] = {"型号", "轴距(mm)", "轮距(mm)", "最小离地间隙(mm)", "最小转弯半径(m)", "驱动形式",
                         "最大行程(km)", "轮胎型号", "轮胎尺寸(mm)"};
    for (int i = 0; i < kPurchaseAmount; ++i)
    {
        // 随机数生成
        srand((unsigned)time(nullptr) * getpid());
        string random_gen = GenRandom(11);
        smartCars[i].id_ = "cqusn" + random_gen;
        // 底盘
        srand((unsigned)time(nullptr) * getpid());
        random_gen = GenRandom(6);
        smartCars[i].underpan_.SetId("dp" + random_gen);
        smartCars[i].underpan_.SetModel(StringInputInformationHelper(underpan[0]));
        smartCars[i].underpan_.SetWheelBase(DoubleInputInformationHelper(underpan[1], 0.0, "轴距输入范围错误"));
        smartCars[i].underpan_.SetAxleTrack(DoubleInputInformationHelper(underpan[2], 0.0, "轮距输入范围错误"));
        // smartCars[i].underpan.setGroundClearance(DoubleInputInformationHelper(underpan[3], 0.0, "最小离地间隙输入范围错误"));
        // smartCars[i].underpan.setMinimumBendingRadius(DoubleInputInformationHelper(underpan[4], 0.0, "最小转弯半径输入范围错误"));
        // smartCars[i].underpan.setDriveForm(StringInputInformationHelper(underpan[5]));
        // smartCars[i].underpan.setBatteryLife(DoubleInputInformationHelper(underpan[6], 0.0, "最大行程输入范围错误"));
        // smartCars[i].underpan.setTireModel(StringInputInformationHelper(underpan[7]));
        // smartCars[i].underpan.setTireSize(DoubleInputInformationHelper(underpan[8], 0.0, "轮胎尺寸输入有误"));
        // // AGXKits
        // smartCars[i].aGXKits.setModel(StringInputInformationHelper("型号"));
        // smartCars[i].aGXKits.setAiHashrate(DoubleInputInformationHelper("AI(TOPS)"));
        // smartCars[i].aGXKits.setCudaCoreNum(DoubleInputInformationHelper("CUDA核心"));
        // smartCars[i].aGXKits.setTensorCore(DoubleInputInformationHelper("Tensor CORE"));
        // smartCars[i].aGXKits.setMemory(DoubleInputInformationHelper("显存(G)"));
        // smartCars[i].aGXKits.setStorage(DoubleInputInformationHelper("存储(G)"));
        // // 双目摄像头
        // smartCars[i].binocularCamera.setModel(StringInputInformationHelper("型号"));
        // smartCars[i].binocularCamera.setCamera(StringInputInformationHelper("摄像头"));
        // smartCars[i].binocularCamera.setRgbFrameResolution(StringInputInformationHelper("RGB帧分辨率"));
        // smartCars[i].binocularCamera.setRgbFramRate(DoubleInputInformationHelper("RGB帧率", 0.0));
        // smartCars[i].binocularCamera.setFov(StringInputInformationHelper("FOV"));
        // smartCars[i].binocularCamera.setFrameRateOfDepth(DoubleInputInformationHelper("深度帧率", 0.0));
        // // 多线激光雷达
        // smartCars[i].liDAR.setModel(StringInputInformationHelper("型号"));
        // smartCars[i].liDAR.setChannelNumber(DoubleInputInformationHelper("通道数", 0.0));
        // smartCars[i].liDAR.setTestScope(DoubleInputInformationHelper("测试范围(m)", 0.0));
        // smartCars[i].liDAR.setPower(DoubleInputInformationHelper("功耗(w)", 0.0));
        // // 9轴陀螺仪
        // smartCars[i].gyroscope.setModel(StringInputInformationHelper("型号"));
        // smartCars[i].gyroscope.setBrand(StringInputInformationHelper("厂商"));
        // // 液晶显示屏
        // smartCars[i].lcd.setModel(StringInputInformationHelper("型号"));
        // smartCars[i].lcd.setSize(DoubleInputInformationHelper("尺寸", 0.0));
        // // 电池模块
        // smartCars[i].batteryModule.setParameter(StringInputInformationHelper("参数"));
        // smartCars[i].batteryModule.setExternalPowerSupply(DoubleInputInformationHelper("对外供电(V)", 0.0));
        // smartCars[i].batteryModule.setChargeTime(DoubleInputInformationHelper("充电时间(H)", 0.0));

        FormatDivision("\n第 " + to_string(i + 1) + " 个小车的数据是", '*', 100);
        smartCars[i].Print();
    }
    kAvailableAmount = kPurchaseAmount;
    FormatDivision("小车信息录入完成", '*', 100);
    return smartCars;
}