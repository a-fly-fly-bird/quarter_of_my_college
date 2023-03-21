#include <iostream>
#include <string>
#include <fstream>
#include "li_dar.h"

using namespace std;

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

void LiDar::Attach(IObserver *observer)
{
    list_observer_.push_back(observer);
}

void LiDar::Detach(IObserver *observer)
{
    list_observer_.remove(observer);
}

void LiDar::Notify()
{
    list<IObserver *>::iterator iterator = list_observer_.begin();
    // HowManyObserver();
    while (iterator != list_observer_.end())
    {
        (*iterator)->Update(message_);
        ++iterator;
    }
}

void LiDar::CreateMessage(string message){
    message_ = message;
    Notify();
}

void LiDar::HowManyObserver(){
    cout << "There are " << list_observer_.size() << " observers in the list." << endl;
}
