// https://www.acmicpc.net/problem/15655
#include <iostream>
#include <algorithm>
using namespace std;

// global variable
int n, m;
int nums[10] = {0,};
vector<int> combination;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> nums[i];
    }
    for(int i = 0;i < n;i++){
        if(i < m){
            combination.push_back(0);
        }else{
            combination.push_back(1);
        }
    }
    // sorting
    sort(nums, nums+n);
    do{
        for(int i = 0;i < n;i++){
            if(combination[i] == 0){
                cout << nums[i] << ' ';
            }
        }
        cout << '\n';
    }while(next_permutation(combination.begin(), combination.end()));
}