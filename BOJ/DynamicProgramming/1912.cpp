// https://www.acmicpc.net/problem/1912
#include <iostream>
#include <vector>
using namespace std;

int n; // input value
int d[100001] = {0,};
int a[100001] = {0,};
vector<int> nums;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0;i < n;i++){
        int num;
        cin >> num;
        nums.push_back(num);
    } // input value
    // init value
    d[1] = nums[0];
    a[1] = nums[0];
    // fill in dp_table
    for(int i = 2;i <= n;i++){
        int accum_max_value = max(nums[i-1], a[i-1] + nums[i-1]);
        d[i] = max(accum_max_value, d[i-1]);
        a[i] = accum_max_value;
    }
    cout << d[n];
}