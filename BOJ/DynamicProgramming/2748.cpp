// https://www.acmicpc.net/problem/2748
#include <iostream>
using namespace std;

int n; // num
long long d[100] = {0,};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    // init value
    d[0] = 0;
    d[1] = 1;
    // fill in dp_table
    for(int i = 2;i <= n;i++){
        d[i] = d[i-1] + d[i-2];
    }
    cout << d[n];
}