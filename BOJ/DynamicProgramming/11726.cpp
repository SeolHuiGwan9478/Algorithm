// https://www.acmicpc.net/problem/11726
#include <iostream>
using namespace std;

int n; // width
int dp_table[1001] = {0,};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // input 
    cin >> n;
    // init value
    dp_table[1] = 1;
    dp_table[2] = 2;
    // fill in dp_table
    for(int i = 3;i <= n;i++){
        dp_table[i] = (dp_table[i-1] + dp_table[i-2]) % 10007;
    }
    // output results
    cout << dp_table[n];
}