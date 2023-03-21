#ifndef UNDER_PAN_H
#define UNDER_PAN_H

#include <string>
#include "printable.h"
#include "saveable.h"
#include "observer_interface.h"

// 底盘
class Underpan : public Printable, public Saveable, public IObserver
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

    std::string message_from_subject_;

    ISubject &subject_;

    static int static_number_;

    // 第几个订阅者
    int number_ = 0;

public:
    Underpan(ISubject &subject);

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

    void Update(const std::string &message_from_subject) override;

    void RemoveMeFromTheList();

    void PrintInfo();

    void Control();
};

#endif