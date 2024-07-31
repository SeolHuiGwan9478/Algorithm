// https://www.acmicpc.net/problem/11931
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> nums;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0;i < n;i++){
        int num;
        cin >> num;
        nums.push_back(num);
    }
    sort(nums.rbegin(), nums.rend());
    for(int i = 0;i < n;i++){
        cout << nums[i] << '\n';
    }
}