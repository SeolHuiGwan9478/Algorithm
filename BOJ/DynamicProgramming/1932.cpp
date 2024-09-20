// https://www.acmicpc.net/problem/1932
#include <iostream>
#include <algorithm>
using namespace std;

int n; // size
int nums[501][501] = {0,}; // input value
int dp_table[501][501] = {0,};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= i;j++){
            cin >> nums[i][j];
        }
    } // input value
    // init value
    dp_table[1][1] = nums[1][1];
    for(int i = 2;i <= n;i++){ // fill in dp_table
        for(int j = 1;j <= i;j++){
            int left_num = -1, right_num = -1;
            if(j-1 > 0) left_num = dp_table[i-1][j-1];
            if(j < i) right_num = dp_table[i-1][j];
            int max_value = max(left_num, right_num);
            dp_table[i][j] = max_value + nums[i][j];
        }
    }
    int max_value = *max_element(dp_table[n]+1, dp_table[n]+1+n);
    cout << max_value;
}