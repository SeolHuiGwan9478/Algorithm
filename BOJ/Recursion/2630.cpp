#include <iostream>
using namespace std;

int n; //가로(또는 세로) 길이
int paper[200][200] = {0,}; //종이 배열
int cnt[2] = {0,};

bool check(int m, int sx, int sy){
    for(int i = sx;i < sx+m;i++){
        for(int j = sy;j < sy+m;j++){
            if(paper[sx][sy] != paper[i][j]) return false;
        }
    }
    return true;
} //같은 색 종이 확인

void div(int m, int sx, int sy){
    if(check(m, sx, sy)){
        int color = paper[sx][sy];
        cnt[color] += 1;
        return;
    }
    int half = m/2;
    div(half, sx, sy);
    div(half, sx, sy+half);
    div(half, sx+half, sy);
    div(half, sx+half, sy+half);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++) cin >> paper[i][j];
    } //paper 배열 입력 완료
    div(n, 0, 0);
    for(int i = 0;i < 2;i++) cout << cnt[i] << '\n';
}