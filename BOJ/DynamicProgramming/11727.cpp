// https://www.acmicpc.net/problem/11727
#include <iostream>
using namespace std;

int n; // width
int dp_table[1001] = {0,}; // dp_table

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n; // input value
    // init value
    dp_table[1] = 1;
    dp_table[2] = 3;
    // fill in dp_table
    for(int i = 3;i <= n;i++){
        dp_table[i] = (dp_table[i-1] + 2 * dp_table[i-2]) % 10007;
    }
    cout << dp_table[n];
}