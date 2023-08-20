// https://www.acmicpc.net/problem/15655
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// global variable
int n, m;
int nums[10] = {0,};
vector<int> seq;

void func(int cnt, int start){
    if(cnt == m){
        for(int i = 0;i < m;i++){
            cout << seq[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = start;i < n;i++){
        seq.push_back(nums[i]);
        func(cnt+1, i+1);
        seq.pop_back();
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