// https://www.acmicpc.net/problem/11055
#include <iostream>
#include <vector>
using namespace std;

int n; // input size
vector<int> nums;
int d[1001] = {0,};
int a[1001] = {0,};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0;i < n;i++){
        int num;
        cin >> num;
        nums.push_back(num);
        a[i] = num;
    } // input value
    // init value
    d[0] = nums[0];
    a[0] = nums[0];
    // fill in dp_table
    for(int i = 1;i < n;i++){
        int num = nums[i];
        d[i] = d[i-1];
        for(int j = 0;j < i;j++){
            if(num > nums[j]){ 
                int candidate_max_val = a[j] + num;
                a[i] = max(candidate_max_val, a[i]);
                d[i] = max(candidate_max_val, d[i]); // update dp_table
            }
        }
    }
    cout << d[n-1];
}