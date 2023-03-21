#include <iostream>
#include <string>
#include <fstream>
#include "under_pan.h"

using namespace std;

int Underpan::static_number_ = 0;

Underpan::Underpan(ISubject &subject) : subject_(subject)
{
    this->subject_.Attach(this);
    std::cout << "Hi, I'm the Underpan No.\"" << ++Underpan::static_number_ << "\".\n";
    this->number_ = Underpan::static_number_;
}

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

void Underpan::Update(const string &message_from_subject)
{
    message_from_subject_ = message_from_subject;
    // PrintInfo();
    Control();
}

void Underpan::RemoveMeFromTheList()
{
    subject_.Detach(this);
    cout << "Underpan \"" << number_ << "\" removed from the list.\n";
}

void Underpan::PrintInfo()
{
    cout << "Underpan \"" << this->number_ << "\": a new message is available --> " << this->message_from_subject_ << endl;
}

void Underpan::Control()
{
    PrintInfo();
    if (message_from_subject_ == "1")
    {
        cout << "前方障碍, 后退。" << endl;
    }
    else if (message_from_subject_ == "2")
    {
        cout << "左前方障碍, 右转。" << endl;
    }
    else if (message_from_subject_ == "3")
    {
        cout << "右前方障碍, 左转。" << endl;
    }else{
        cout << "无效状态。" << endl;
    }
}
