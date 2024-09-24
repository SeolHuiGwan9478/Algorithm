// https://www.acmicpc.net/problem/9461
#include <iostream>
#include <vector>
using namespace std;

int t; // test case
long long d[100] = {1,1,1,2,2};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t; // input t
    for(int i = 0;i < t;i++){
        long long num;
        cin >> num;
        for(int j = 5;j < num;j++){
            d[j] = d[j-1] + d[j-5];
        }
        cout << d[num-1] << '\n';
    } // input value
}