#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int n;
unordered_map<long, int> counts;
vector<pair<long, int>> nums;

bool compare(const pair<long,int>& a, const pair<long,int>& b){
    if(a.second > b.second){
        return true;
    }else if(a.second == b.second){
        return a.first < b.first;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0;i < n;i++){
        long num;
        cin >> num;
        if(counts.find(num) == counts.end()){
            counts[num] = 1;
        }else{
            counts[num]++;
        }
    }
    for(auto& it : counts){
        nums.push_back(it);
    }
    sort(nums.begin(), nums.end(), compare);
    cout << nums[0].first;
}