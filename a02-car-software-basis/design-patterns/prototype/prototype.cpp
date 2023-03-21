#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

enum Type
{
    PROTOTYPE_1 = 0,
    PROTOTYPE_2
};

class Cloneable
{
protected:
    string type_;
    int value_;

public:
    Cloneable() {}
    Cloneable(int value) : value_(value) {}
    virtual ~Cloneable() {}
    // 纯虚函数
    virtual Cloneable *clone() const = 0;
    string getType();
    int getValue();
    void show()
    {
        cout << "type: " << type_ << " value: " << value_ << endl;
    }
};

class ConcretePrototype1 : public Cloneable
{
public:
    ConcretePrototype1(int value) : Cloneable(value)
    {
        type_ = "ConcretePrototype1";
    }
    Cloneable *clone() const override
    {
        return new ConcretePrototype1(*this);
    }
};

class ConcretePrototype2 : public Cloneable
{
public:
    ConcretePrototype2(int value) : Cloneable(value)
    {
        type_ = "ConcretePrototype2";
    }
    Cloneable *clone() const override
    {
        return new ConcretePrototype2(*this);
    }
};

// 克隆工厂，保证原型的独特性

class PrototypeFactory
{
private:
    unordered_map<Type, Cloneable *, hash<int>> prototypes_;

public:
    PrototypeFactory()
    {
        prototypes_[Type::PROTOTYPE_1] = new ConcretePrototype1(1);
        prototypes_[Type::PROTOTYPE_2] = new ConcretePrototype2(20);
    }
    ~PrototypeFactory()
    {
        delete prototypes_[Type::PROTOTYPE_1];
        delete prototypes_[Type::PROTOTYPE_2];
    }
    Cloneable *CreatePrototype(Type type)
    {
        return prototypes_[type]->clone();
    }
};

int main()
{
    PrototypeFactory *prototype_factory = new PrototypeFactory();
    Cloneable *prototype1 = prototype_factory->CreatePrototype(Type::PROTOTYPE_1);
    prototype1->show();
    Cloneable *prototype2 = prototype_factory->CreatePrototype(Type::PROTOTYPE_2);
    prototype2->show();
    delete prototype1;
    delete prototype2;
    delete prototype_factory;
}