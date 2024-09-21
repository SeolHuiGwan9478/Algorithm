// https://www.acmicpc.net/problem/2193
#include <iostream>
using namespace std;

int n; // input n
long long dp_table[91][2] = {0,};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    // init value
    dp_table[1][0] = 0;
    dp_table[1][1] = 1;
    // fill in dp_table
    for(int i = 2;i <= n;i++){
        dp_table[i][0] = dp_table[i-1][0] + dp_table[i-1][1];
        dp_table[i][1] = dp_table[i-1][0];
    }
    long long count = dp_table[n][0] + dp_table[n][1];
    cout << count;
}