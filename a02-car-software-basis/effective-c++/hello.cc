#include<iostream>
using namespace std;

/*
基类派生类的赋值构造和virtual多态的细节
*/
class A{
public:
    virtual void hello(){
        cout << "I'm A" << endl;
    }
};

class B: public A{
public:
    void hello() override{
        cout << "I'm B" << endl;
    }

    void print(){
        cout << "Dericed class own." << endl;
    }
};

// int main(){
//     A a;
//     a.hello();
//     B b;
//     b.hello();
//     a = b;
//     a.hello();
// }

// int main(){
//     A* a = new A();
//     B* b = new B();
//     a->hello();
//     b->hello();
//     a = b;
//     a->hello();
//     return 0;
// }

int main(){
    A* a = new A();
    B* b = new B();
    a->hello();
    b->hello();
    a = b;
    // 直接报错
    // a->print();
    return 0;
}