#include <iostream>
#include <string>

using namespace std;

class Product
{
public:
    virtual ~Product(){};
    virtual string Operation() const = 0;
};

class Product1 : public Product
{
public:
    string Operation() const
    {
        return "{Result of the Product1}";
    }
};

class Product2 : public Product
{
public:
    string Operation() const
    {
        return "{Result of the Product2}";
    }
};

class Creator
{
public:
    virtual ~Creator(){};
    virtual Product *FactoryMethod() const = 0;
    std::string SomeOperation() const
    {
        // Call the factory method to create a Product object.
        Product *product = this->FactoryMethod();
        // Now, use the product.
        std::string result = "Creator: The same creator's code has just worked with " + product->Operation();
        delete product;
        return result;
    }
};

class Creator1 : public Creator
{
public:
    Product *FactoryMethod() const
    {
        return new Product1();
    }
};

class Creator2 : public Creator
{
public:
    Product *FactoryMethod() const
    {
        return new Product2();
    }
};

void ClientCode(const Creator &creator)
{
    std::cout << "Client: I'm not aware of the creator's class, but it still works.\n"
              << creator.SomeOperation() << std::endl;
}

int main(){
    ClientCode(*new Creator1());
    ClientCode(*new Creator2());
}