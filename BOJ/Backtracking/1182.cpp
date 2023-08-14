#include <iostream>
using namespace std;

int n, s;
int cnt = 0;
int nums[20];

void func(int sum, int cur_node){
    if(cur_node == n){
        if(sum == s){
            cnt++;
        }
        return;
    }
    func(sum,cur_node+1);
    func(sum+nums[cur_node],cur_node+1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // input n, s, nums
    cin >> n >> s;
    for(int i = 0;i < n;i++){
        cin >> nums[i];
    }
    func(0, 0);
    // 공집합 제거
    if(s == 0) cnt--;
    cout << cnt;
}