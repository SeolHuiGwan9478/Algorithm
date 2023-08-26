// https://www.acmicpc.net/problem/1759
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// global variable
int l, c;
int v_cnt = 0, c_cnt = 0; // 모음, 자음 개수
char chars[20];
char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
vector<char> pwd;

void func(int cnt, int start){
    if(cnt == l){
        if(v_cnt >= 1 && c_cnt >= 2){
            for(int i = 0;i < l;i++){
                cout << pwd[i];
            }
            cout << '\n';
        }
        return;
    }
    for(int i = start;i < c;i++){
        bool is_vowel = false;
        for(int j = 0;j < 5;j++){
            if(chars[i] == vowels[j]){
                is_vowel = true;
                break;
            }
        }
        if(is_vowel) v_cnt += 1;
        else c_cnt += 1;
        pwd.push_back(chars[i]);
        func(cnt+1, i+1);
        if(is_vowel) v_cnt -= 1;
        else c_cnt -= 1;
        pwd.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> l >> c;
    for(int i = 0;i < c;i++){
        cin >> chars[i];
    }
    sort(chars, chars+c);
    func(0, 0);
    return 0;
}