#ifndef BIND_INFO_H
#define BIND_INFO_H

#include "printable.h"
#include "saveable.h"
#include "smart_car.h"
#include "student.h"
#include <string>
#include <map>

static int kPurchaseAmount = 100;
static int kAvailableAmount = 100;
static int kStudentAmount = 100;

class BindInfo : public Printable, public Saveable
{
private:
    Student *student_;
    SmartCar *smart_car_;

public:
    Student *GetStudent() const;

    void SetStudent(Student *);

    SmartCar *GetSmartCar() const;

    void SetSmartCar(SmartCar *);

    void Print() const override;

    bool Save(const std::string &) const override;

    friend std::ostream &operator<<(std::ostream &, const BindInfo &);
};

static std::map<std::string, BindInfo *> kBindMap;

bool SaveMap(std::string);

bool ReadInfoFromFile(std::string);

BindInfo *GetBindInfo(const std::string &);

bool MapBind(BindInfo *);

bool Bind(Student *, SmartCar *, BindInfo *);

Student *InputStudents();

SmartCar *InputInformation();

#endif