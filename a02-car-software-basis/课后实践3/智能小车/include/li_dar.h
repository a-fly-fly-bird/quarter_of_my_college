#ifndef LI_DAR_H
#define LI_DAR_H

#include<string>
#include"printable.h"
#include"saveable.h"
#include"observer_interface.h"

// 多线激光雷达
class LiDar : public Printable, public Saveable, public ISubject
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

    std::list<IObserver *> list_observer_;
    
    std::string message_;

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

    void Attach(IObserver *observer) override;

    void Detach(IObserver *observer) override;

    void Notify() override;

    void CreateMessage(std::string message = "Empty");

    void HowManyObserver();
};

#endif
