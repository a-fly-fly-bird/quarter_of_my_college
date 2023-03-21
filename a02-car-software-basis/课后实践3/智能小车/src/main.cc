#include"under_pan.h"
#include"li_dar.h"

using namespace std;

int main(){
    LiDar* li_dar = new LiDar;
    Underpan *observer1 = new Underpan(*li_dar);
    Underpan *observer2 = new Underpan(*li_dar);
    Underpan *observer3 = new Underpan(*li_dar);

    string input;

    while(input != "exit"){
        cout << "\n请输入前方路况。1代表前方障碍，2代表左前方障碍，3代表右前方障碍。输入exit退出。\n" << endl;
        cin >> input;
        li_dar->CreateMessage(input);
    }

    delete observer3;
    delete observer2;
    delete observer1;
    delete li_dar;
    return 0;
}