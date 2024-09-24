// https://www.acmicpc.net/problem/11053
#include <iostream>
#include <vector>
using namespace std;

int n; // input size
vector<int> nums;
int d[1001] = {0,};
int a[1001] = {0,};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0;i < n;i++){
        int num;
        cin >> num;
        nums.push_back(num);
        a[i] = 1;
    } // input value
    // init value
    
    // fill in dp_table
    for(int i = 1;i < n;i++){
        int num = nums[i];
        d[i] = d[i-1];
        for(int j = 0;j < i;j++){
            if(num > nums[j]){
                a[i] = max(a[i], a[j] + 1);
                d[i] = max(a[i], d[i]);
            }
        } 
    }
    cout << d[n-1];
}