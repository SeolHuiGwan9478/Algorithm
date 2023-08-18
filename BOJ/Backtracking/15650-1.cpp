#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int cnt = 0;
vector<int> nums;
vector<int> combination;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        nums.push_back(i);
        if(cnt < m){
            combination.push_back(0);
            cnt++;
        }else{ combination.push_back(1);}
    }
    do{
        for(int i = 0;i < n;i++){
            if(combination[i] == 0){
                cout << nums[i] << " ";
            }
        }
        cout << "\n";
    }while(next_permutation(combination.begin(), combination.end()));
}