#include <iostream>
#include <string>

using namespace std;

struct CarInfo
{
    string name;
    float battery_life;
    int rpm;
};

CarInfo* GetCarInfo(){
    CarInfo* car = new CarInfo();
    car->name = "Tesla";
    car->battery_life = 100.0;
    car->rpm = 1000;
    return car;
}

extern "C"
{
    CarInfo* PyGetCarInfo()
    {
        return GetCarInfo();
    }
}
