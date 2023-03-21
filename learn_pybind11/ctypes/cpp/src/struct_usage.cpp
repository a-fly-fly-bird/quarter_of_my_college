#include<iostream>
#include<string>

using namespace std;

struct Student
{
    string name;
    float fScore[3];
};

void Display(Student su)
{
    cout << su.name << endl;
}

extern "C" 
{
    void CppDisplay(Student su){
        Display(su);
        su.name = "name has been changed";
        Display(su);
    }
}