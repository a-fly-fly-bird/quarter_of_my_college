#include<vector>
#include<iostream>
#include <algorithm>

using namespace std;


bool compare(int a,int b) 
{ 
    return a > b;
}

int main(){
    vector<int> v(10, 0);
    int num = 0;
    for(vector<int>::iterator iter = v.begin() ; iter != v.end(); ++iter){
        *iter = num++;
    }
    v.push_back(10);
    for(vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter){
        cout << *iter << " ";
    }
    cout << endl;
    v.erase(v.begin() + 5);
    for(vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter){
        cout << *iter << " ";
    }
    cout << endl;
    cout << v.at(5) << endl;
    cout << v.size() << endl;
    cout << v.capacity() << endl;
    sort(v.begin(), v.end(), compare);
    for(vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter){
        cout << *iter << " ";
    }
    cout << endl;
    v[0] = -100;
    for(vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter){
        cout << *iter << " ";
    }
}