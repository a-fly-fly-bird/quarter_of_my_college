#include <iostream>
#include "student.h"
#include <fstream>

// cc文件里可以使用namespace
using namespace std;

const string &Student::GetId() const
{
    return id_;
}

void Student::SetId(const string &id)
{
    Student::id_ = id;
}

const string &Student::GetName() const
{
    return name_;
}

void Student::SetName(const string &name)
{
    Student::name_ = name;
}

void Student::Print() const
{
    cout << *this << endl;
}

bool Student::Save(const string &filename) const
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
    return os << "学生的编号是：" << student.GetId() << endl
              << "姓名是：" << student.GetName() << endl;
}