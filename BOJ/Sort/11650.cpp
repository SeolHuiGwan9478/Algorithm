// https://www.acmicpc.net/problem/11650
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> xys;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0;i < n;i++){ // input
        pair<int, int> xy;
        cin >> xy.first >> xy.second;
        xys.push_back(xy);
    }
    sort(xys.begin(), xys.end());
    for(int i = 0;i < n;i++){
        pair<int, int> xy = xys[i];
        cout << xy.first << ' ' << xy.second << '\n';
    }
}