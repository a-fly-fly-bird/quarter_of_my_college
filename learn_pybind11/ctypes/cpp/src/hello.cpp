#include <iostream>
#include <string>
using namespace std;
extern "C"
{
    int SayHi()
    {
        cout << "hello world" << endl;
        return 0;
    }
}