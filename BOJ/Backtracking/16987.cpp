// https://www.acmicpc.net/problem/16987
#include <iostream>
using namespace std;

// global variable
int n; // 계란 개수
int s[10] = {0,}; // 계란의 내구도
int w[10] = {0,}; // 계란의 무게
int max_broken = 0; // 깨진 계란의 개수

void func(int cur){
    if(cur == n){
        int broken_egg = 0;
        for(int i = 0;i < n;i++){
            if(s[i] <= 0) broken_egg += 1;
        }
        if(max_broken < broken_egg) max_broken = broken_egg;
        return;
    }
    // 손에 든 계란의 내구도가 0 이하인 경우
    if(s[cur] <= 0){
        func(cur+1);
        return;
    }
    // 깨지지 않은 다른 계란이 없는 경우
    bool has_broken = false;
    for(int i = 0;i < n;i++){
        if(i != cur && s[i] > 0){
            has_broken = true;
            break;
        }
    }
    if(!has_broken){
        func(cur+1);
        return;
    }else{ // 깰 수 있는 계란이 있는 경우
        for(int i = 0;i < n;i++){
            // 자기 자신 또는 내구도가 0이하인 경우
            if(i == cur || s[i] <= 0) continue;
            // 계란1, 계란2 내구도 변경
            s[cur] -= w[i];
            s[i] -= w[cur];
            func(cur+1);
            s[cur] += w[i];
            s[i] += w[cur];
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> s[i] >> w[i];
    }
    func(0);
    cout << max_broken;
    return 0;
}