// https://www.acmicpc.net/problem/11659
#include <iostream>
#include <vector>
using namespace std;

int n, m; // input n, m
vector<int> nums;
int dp_table[100001] = {0,};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0;i < n;i++){ // input nums
        int num;
        cin >> num;
        nums.push_back(num);
    }
    dp_table[1] = nums[0];
    for(int i = 2;i <= n;i++){ // fill in dp_table
        dp_table[i] = dp_table[i-1] + nums[i-1];
    }
    for(int k = 0;k < m;k++){
        int i, j;
        cin >> i >> j;
        cout << dp_table[j] - dp_table[i-1] << '\n';
    }
}