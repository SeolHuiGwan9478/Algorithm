// https://www.acmicpc.net/problem/15663
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// global variable
int n, m;
int nums[10] = {0,};
int isused[10] = {0,};
vector<int> seq;

void func(int cnt){
    int pre_num = 0; // 같은 레벨에서 이전 노드 번호 저장하기 위한 변수
    if(cnt == m){
        for(int i = 0;i < m;i++){
            cout << seq[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 0;i < n;i++){
        if(isused[i] != 1 && pre_num != nums[i]){
            isused[i] = 1;
            seq.push_back(nums[i]);
            pre_num = nums[i]; // 이전 번호 업데이트
            func(cnt+1);
            isused[i] = 0;
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
    return 0;
}