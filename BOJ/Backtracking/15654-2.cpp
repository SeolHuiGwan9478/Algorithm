// https://www.acmicpc.net/problem/15654
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int nums[10] = {0,}; // N개의 수를 저장할 벡터

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    // n개의 숫자 입력
    for(int i = 0;i < n;i++){
        cin >> nums[i];
    }
    sort(nums, nums+n); // 오름차순 정렬
    do{
        for(int i = 0;i < m;i++){
            cout << nums[i] << ' ';
        }
        cout << '\n';
        reverse(nums+m, nums+n);
    }while(next_permutation(nums, nums+n));
    return 0;
}