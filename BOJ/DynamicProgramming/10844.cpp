// https://www.acmicpc.net/problem/10844
#include <iostream>
#include <algorithm>
using namespace std;

int n; // steps num
long long d[105][10] = {0,};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long count = 0;
    cin >> n; // input value
    // init value
    for(int i = 1;i <= 9;i++){
        d[1][i] = 1;
    }
    // fill in dp_table
    for(int i = 2;i <= n;i++){
        for(int j = 0;j <= 9;j++){
            if(j == 0){
                d[i][j] = d[i-1][1];
            }else if(j == 9){
                d[i][j] = d[i-1][8];
            }else{
                d[i][j] = (d[i-1][j-1] + d[i-1][j+1]) % 1000000000;
            }
        }
    }
    for(int i = 0;i <= 9;i++){
        count += d[n][i];
    }
    cout << count % 1000000000;
}