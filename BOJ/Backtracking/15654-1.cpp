// https://www.acmicpc.net/problem/15654
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int nums[10] = {0,}; // N개의 수를 저장할 벡터
int isused[10] = {0,}; // 마킹(Marking) 배열
vector<int> seq;  // 순열을 저장할 벡터

void func(int cnt){
    if(cnt == m){
        for(int i = 0;i < m;i++){
            cout << seq[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 0;i < n;i++){
        if(isused[i] != 1){
            isused[i] = 1;
            seq.push_back(nums[i]);
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
    // n개의 숫자 입력
    for(int i = 0;i < n;i++){
        cin >> nums[i];
    }
    sort(nums, nums+n);
    func(0);
}