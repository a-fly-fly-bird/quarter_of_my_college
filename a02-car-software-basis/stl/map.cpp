#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(){
    map<int, string> stu = {
        {1, "Tom"},
        {2, "Jack"},
        {3, "Mary"},
        {4, "Alice"},
        {5, "Bob"}
    };
    stu.insert(pair<int, string>(6, "Li Hua"));
    map<int, string>::iterator it;
    for(it = stu.begin(); it != stu.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
    pair<map<int, string>::iterator, bool> ret;
    ret = stu.insert(pair<int, string>(6, "Li Hua"));
    if(ret.second == false){
        cout << "element already existed";
    }
    stu[6] = "Lucas";
    for(it = stu.begin(); it != stu.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
}