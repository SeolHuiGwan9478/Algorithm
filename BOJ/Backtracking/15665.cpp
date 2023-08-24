// https://www.acmicpc.net/problem/15665
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// global variable
int n, m;
int nums[10] = {0,};
vector<int> seq;

// recursion func
void func(int cnt){
    // local variable
    int pre_num = 0;
    // base condition
    if(cnt == m){
        for(int i = 0;i < m;i++){
            cout << seq[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 0;i < n;i++){
        if(pre_num != nums[i]){
            seq.push_back(nums[i]);
            func(cnt+1);
            pre_num = nums[i];
            seq.pop_back();
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> nums[i];
    }
    sort(nums, nums+n);
    func(0);
}