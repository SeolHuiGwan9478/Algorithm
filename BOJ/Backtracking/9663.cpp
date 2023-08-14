#include <iostream>
using namespace std;

int n;
int cnt = 0; // 경우의 수
int isused1[40] = {0, }; // 세로 마킹
int isused2[40] = {0, }; // 좌측 상향 대각선 마킹
int isused3[40] = {0, }; // 우측 상향 대각선 마킹

void func(int k){
    if(k == n){
        cnt++;
        return;
    }
    for(int i = 0;i < n;i++){
        if(isused1[i] != 1 && isused2[k-i+n-1] != 1 && isused3[k+i] != 1){
            isused1[i] = 1;
            isused2[k-i+n-1] = 1;
            isused3[k+i] = 1;
            func(k+1);
            isused1[i] = 0;
            isused2[k-i+n-1] = 0;
            isused3[k+i] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    func(0);
    cout << cnt;
}