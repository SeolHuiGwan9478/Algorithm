#include <iostream>
using namespace std;

//배열 최대 값 pow(3,7) 출력해보니 2187
int n; //가로 또는 세로 길이
int paper[2200][2200] = {0,}; //종이 배열
int cnt[3] = {0,}; //숫자 개수 배열

bool check(int m, int sx, int sy){
    for(int i = sx;i < sx + m;i++){
        for(int j = sy;j < sy + m;j++){
            if(paper[sx][sy] != paper[i][j]) return false;
        }
    }
    return true;
} //같은 수로 이뤄진 종이인지 확인 함수

void div(int m, int sx, int sy){
    if(check(m, sx, sy)){
        int num = paper[sx][sy];
        if(num == -1) cnt[0] += 1;
        else if(num == 0) cnt[1] += 1;
        else cnt[2] += 1;
        return;
    }
    int divm = m/3;
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            div(divm, sx+divm*i, sy+divm*j);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++) cin >> paper[i][j]; //종이 수 입력받기
    }
    div(n, 0, 0);
    for(int i = 0;i < 3;i++) cout << cnt[i] << '\n';
}