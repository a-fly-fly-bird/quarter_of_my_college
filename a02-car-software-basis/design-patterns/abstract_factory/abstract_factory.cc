#include <iostream>
#include <string>
using namespace std;

class AbstractProductA
{
public:
    virtual ~AbstractProductA() {}
    virtual string UserfulFunctoinA() const = 0;
};

class ConcreteProductA1 : public AbstractProductA
{
public:
    string UserfulFunctoinA() const override
    {
        return "The result of the product A1.";
    }
};

class ConcreteProductA2 : public AbstractProductA
{
public:
    string UserfulFunctoinA() const override
    {
        return "The result of the product A2.";
    }
};

class AbstractProductB
{
public:
    virtual ~AbstractProductB() {}
    virtual string UserfulFunctoinB() const = 0;
};

class ConcreteProductB1 : public AbstractProductB
{
public:
    string UserfulFunctoinB() const override
    {
        return "The result of the product B1.";
    }
};

class ConcreteProductB2 : public AbstractProductB
{
public:
    string UserfulFunctoinB() const override
    {
        return "The result of the product B2.";
    }
};

class AbastractFactory
{
public:
    virtual AbstractProductA *CreateProductA() const = 0;
    virtual AbstractProductB *CreateProductB() const = 0;
};

class ConcreateFactory1 : public AbastractFactory
{

public:
    AbstractProductA *CreateProductA() const override
    {
        return new ConcreteProductA1();
    }

    AbstractProductB *CreateProductB() const override
    {
        return new ConcreteProductB1();
    }
};

class ConcreateFactory2 : public AbastractFactory{
public:
    AbstractProductA *CreateProductA() const override
    {
        return new ConcreteProductA2();
    }

    AbstractProductB *CreateProductB() const override
    {
        return new ConcreteProductB2();
    }
};

void ClientCode(const AbastractFactory& factory){
    const AbstractProductA* product_a = factory.CreateProductA();
    const AbstractProductB* product_b = factory.CreateProductB();
    cout << product_a->UserfulFunctoinA() << endl;
    cout << product_b->UserfulFunctoinB() << endl;
    delete product_a;
    delete product_b;
}

int main()
{
    ConcreateFactory1 *f1 = new ConcreateFactory1();
    ClientCode(*f1);
    delete f1;
    ConcreateFactory2 *f2 = new ConcreateFactory2();
    ClientCode(*f2);
    delete f2;
}