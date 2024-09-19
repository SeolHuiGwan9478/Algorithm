// https://www.acmicpc.net/problem/12852
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n; // input n
int d[1000001] = {0,}; // dp_table
int h[1000001]  = {0,};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    // init values
    d[1] = 0;
    // fill in dp_table
    for(int i = 2;i <= n;i++){
        vector<int> tmp_nums;
        vector<int> indices;
        if(i % 2 == 0){
            tmp_nums.push_back(d[i/2]);
            indices.push_back(i/2);
        }
        if(i % 3 == 0){
            tmp_nums.push_back(d[i/3]);
            indices.push_back(i/3);
        }
        tmp_nums.push_back(d[i-1]);
        indices.push_back(i-1);
        int index = min_element(tmp_nums.begin(), tmp_nums.end()) - tmp_nums.begin();
        int min_value = tmp_nums[index];
        int min_index = indices[index];
        d[i] = min_value + 1;
        h[i] = min_index;
    }
    cout << d[n] << '\n';
    cout << n << ' ';
    int idx = n;
    for(int i = 0;i < d[n];i++){
        cout << h[idx] << ' ';
        idx = h[idx];
    }
}