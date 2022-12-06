#include <iostream>
using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x){
    dat[pos++] = x;
}

void pop(){
    if(pos == 0) cout << -1 << '\n';
    else{
        pos--;
        cout << dat[pos] << '\n';
        dat[pos] = 0;
    }
}

void size(){
    cout << pos << '\n';
}

void empty(){
    if(pos == 0) cout << 1 << '\n';
    else cout << 0 << '\n';
}

void top(){
    if(pos == 0) cout << -1 << '\n';
    else cout << dat[pos-1] << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    string cmd;

    cin >> N;
    for(int i = 0;i < N;i++){
        cin >> cmd;
        if(cmd == "push"){
            int num;
            cin >> num;
            push(num);
        }
        else if(cmd == "top") top();
        else if(cmd == "pop") pop();
        else if(cmd == "empty") empty();
        else if(cmd == "size") size();
    }
}