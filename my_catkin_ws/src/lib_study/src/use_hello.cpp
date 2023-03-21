#include "lib_study/hello.h"

#include<iostream>

using namespace std;

int main(){
    my_math_lib::Complex<int> complex(1, 2);
    cout << complex << endl;
}