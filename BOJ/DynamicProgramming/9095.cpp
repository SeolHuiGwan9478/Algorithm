// https://www.acmicpc.net/problem/9095
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t;
int d[12] = {0,};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for(int i = 0;i < t;i++){
        int num;
        fill_n(d, 12, 0); // clear
        d[1] = 1; // set init value
        d[2] = 2;
        d[3] = 4;
        cin >> num;
        for(int j = 4;j <= num;j++){
            d[j] = d[j-1] + d[j-2] + d[j-3];
        }
        cout << d[num] << '\n';
    }
}