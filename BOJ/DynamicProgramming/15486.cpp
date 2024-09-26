// https://www.acmicpc.net/problem/15486
#include <iostream>
#include <algorithm>
using namespace std;

int n; // size
int t[1500005] = {0,}; // time dp_table
int p[1500005] = {0,}; // price dp_table
int d[1500005] = {0,}; // dp_table

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> t[i] >> p[i];
    } // input value
    // fill in dp_table
    for(int i = n;i >= 1;i--){
        if(i + t[i] - 1 <= n){ // 상담이 가능할 때
            d[i] = max(d[i+1], p[i] + d[i + t[i]]);
        }else{
            d[i] = d[i + 1];
        }
    }
    cout << *max_element(d+1, d+n+1);
}