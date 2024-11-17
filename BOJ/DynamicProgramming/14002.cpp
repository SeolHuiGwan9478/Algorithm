// https://www.acmicpc.net/problem/14002
#include <iostream>
using namespace std;

int n; // size
int a[1005] = {0,}; // nums array
int d[1005] = {0,};
int max_n[1005] = {0,};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    } // input num
    // init value
    d[1] = 1;
    max_n[1] = a[1];
    // fill in dp_table
    for(int i = 2;i <= n;i++){
        int num = a[i];
        if(num < a[])
    }
}