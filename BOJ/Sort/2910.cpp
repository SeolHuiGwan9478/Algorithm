// https://www.acmicpc.net/problem/2910
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, c;
int num;
vector<pair<int, int>> nums;

bool is_exist(const pair<int, int>& o){
    return o.first == num;
}

bool compare(const pair<int, int>& a, const pair<int, int>& b){
    return a.second > b.second;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> c;
    for(int i = 0;i < n;i++){
        cin >> num;
        auto iter = find_if(nums.begin(), nums.end(), is_exist);
        if(iter == nums.end()){
            nums.push_back({num, 1});
        }else{
            (*iter).second += 1;
        }
    }
    stable_sort(nums.begin(), nums.end(), compare);
    for(int i = 0;i < nums.size();i++){
        pair<int, int> cur_num = nums[i];
        for(int j = 0;j < cur_num.second;j++){
            cout << cur_num.first << ' ';
        }
    }
}