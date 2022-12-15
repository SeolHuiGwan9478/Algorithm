#include <iostream>
using namespace std;

const int MX = 10000;
int dat[2*MX];
int head = MX, tail = MX;

void push_front(int x){
    dat[--head] = x;
}
void push_back(int x){
    dat[tail++] = x;
}
void pop_front(){
    if(head == tail) cout << -1 << '\n';
    else{
        cout << dat[head] << '\n';
        head++;
    }
}
void pop_back(){
    if(head == tail) cout << -1 << '\n';
    else{
        cout << dat[tail-1] << '\n';
        tail--;
    }
}
void size(){
    cout << tail-head << "\n";
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
        if(cmd == "push_back"){
            int num;
            cin >> num;
            push_back(num);
        }
        else if(cmd == "push_front"){
            int num;
            cin >> num;
            push_front(num);
        }
        else if(cmd == "pop_front") pop_front();
        else if(cmd == "pop_back") pop_back();
        else if(cmd == "size") size();
        else if(cmd == "empty") empty();
        else if(cmd == "front") front();
        else if(cmd == "back") back();
    }
}