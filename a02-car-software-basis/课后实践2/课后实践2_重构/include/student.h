#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "printable.h"
#include "saveable.h"

// .h should not use namespace
// 学生信息
class Student: public Printable, public Saveable
{
private:
    // 根据Google命名规范，类属性以_结尾
    // 学号
    std::string id_;
    // 姓名
    std::string name_;

public:
    const std::string &GetId() const;

    void SetId(const std::string &);

    const std::string &GetName() const;

    void SetName(const std::string &);

    void Print() const;

    bool Save(const std::string &) const;

    friend std::ostream &operator<<(std::ostream &, const Student &);
};

#endif