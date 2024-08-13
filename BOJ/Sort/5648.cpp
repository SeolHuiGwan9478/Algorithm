// https://www.acmicpc.net/problem/5648
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long n;
vector<string> str_nums;
vector<long> l_nums;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(long i = 0;i < n;i++){
        string str_num;
        cin >> str_num;
        reverse(str_num.begin(), str_num.end());
        str_nums.push_back(str_num);
    }
    for(long i = 0;i < n;i++){
        long l_num = stol(str_nums[i]);
        l_nums.push_back(l_num);
    }
    sort(l_nums.begin(), l_nums.end());
    for(long i = 0;i < n;i++){
        cout << l_nums[i] << "\n";
    }
}