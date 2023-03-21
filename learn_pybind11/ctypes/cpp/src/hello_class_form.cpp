#include <iostream>
#include <string>
using namespace std;

class TestClass
{
public:
    char* func();
};

char* TestClass::func() 
{
    cout << "In func without argument" << endl;
    char* temp = "In func without argument";
    return temp;
   
}

extern "C" 
{
    TestClass A;
    char* myfunc1() 
    {
        return A.func(); 
    }

}
