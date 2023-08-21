// https://www.acmicpc.net/problem/15664
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// global variable
int n, m;
int nums[10] = {0,};
vector<int> seq;

void func(int cnt, int start){
    int pre_num = 0;
    if(cnt == m){
        for(int i = 0;i < m;i++){
            cout << seq[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = start;i < n;i++){
        if(pre_num != nums[i]){ // 이전 탐색 값과 현재 탐색 값이 같지 않다면
            seq.push_back(nums[i]);
            pre_num = nums[i]; // 이전 탐색 값 업데이트
            func(cnt+1, i+1);
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
    func(0, 0);
    return 0;
}