#include <iostream>
using namespace std;

int counts[201];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, v, idx;
    cin >> n;
    int* nums = new int[n];
    for(int i = 0;i < n;i++){ //N개의 정수 입력받기
        cin >> nums[i];
    }
    cin >> v;
    for(int i = 0;i < n;i++){ //N개의 정수에 대해 개수를 세어 counts에 기록
        idx = nums[i];
        if(idx < 0){ //음수 입력경우 -1 곱하고 + 100으로 처리 배열의 인덱스는 음수가 없기 때문
            idx *= -1;
            idx += 100;
        }
        counts[idx] += 1;
    }
    if(v < 0){ // v가 음수일 경우도 처리
        v *= -1;
        v += 100;
    }
    cout << counts[v];
}