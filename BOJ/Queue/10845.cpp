#include <iostream>
using namespace std;

const int MX = 10005;
int dat[MX];
int head = 0, tail = 0;

void push(int x){
    dat[tail++] = x;
}

void pop(){
    if(head == tail) cout << -1 << '\n';
    else cout << dat[head++] << '\n';
}

void size(){
    cout << tail - head << '\n';
}

void empty(){
    if(head == tail) cout << 1 << '\n';
    else cout << 0 << '\n';
}

void front(){
    if(head == tail) cout << -1 << '\n';
    else cout << dat[head] << '\n';
}

void back(){
    if(head == tail) cout << -1 << '\n';
    else cout << dat[tail-1] << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        string cmd;
        cin >> cmd;
        if(cmd == "push"){
            int num;
            cin >> num;
            push(num);
        }
        else if(cmd == "pop") pop();
        else if(cmd == "size") size();
        else if(cmd == "empty") empty();
        else if(cmd == "front") front();
        else if(cmd == "back") back();
    }
    return 0;
}