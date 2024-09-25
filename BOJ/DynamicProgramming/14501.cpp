// https://www.acmicpc.net/problem/14501
#include <iostream>
#include <algorithm>
using namespace std;

int n; // size
int max_value = 0;
int t[20] = {0,}; // times
int p[20] = {0,}; // prices
int d[20] = {0,}; // dp_table

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n; // input value
    for(int i = 1;i <= n;i++){
        cin >> t[i] >> p[i];
    }
    // fill in dp_table
    for(int i = n;i >= 1;i--){
        if(i + t[i] - 1 <= n){
            d[i] = p[i] + *max_element(d+i+t[i], d+n+1);
            max_value = max(d[i], max_value);
        }
    }
    cout << max_value;
}