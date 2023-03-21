#include <iostream>
#include <string>

using namespace std;

int main(){
    string* s = new string("hello");
    string& s_r = *s;
    cout << s_r;
    delete s;
}