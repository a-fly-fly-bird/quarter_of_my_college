#include<deque>
#include<iostream>
#include<string>

using namespace std;

int main(){
    deque<string> d;
    int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
    for (int i = 0; i <= 9; i++)
	{
		if (i % 2 == 0)
			d.push_front(to_string(a[i]));
		else
			d.push_back(to_string(a[i]));
	}      
    deque<string>::iterator it;
    for(it = d.begin(); it != d.end(); it++){
        cout << *it << " ";
    }
}