// https://www.acmicpc.net/problem/1799
#include <iostream>
#include <vector>
#define X first;
#define Y second;
using namespace std;

int n; // chess board size
int bishop[10][10]; // chess board
int left_upper[20] = {0,}; // 좌측 상향 대각선
int right_upper[20] = {0,}; // 우측 상향 대각선
int cross_cnt; // 대각선 개수
int max_cnt = 0; // 대각선 최대 개수
vector<vector<pair<int, int>>> v;

void func(int cross_num, int cnt){
    int cur_cnt = cnt;
    // 가지치기
    if(max_cnt >= cur_cnt+cross_cnt-cross_num+1){
        return;
    }
    if(cross_num == cross_cnt){
        if(max_cnt < cur_cnt){
            max_cnt = cur_cnt;
        }
        return;
    }
    for(int i = 0;i < v[cross_num].size();i++){
        pair<int, int> cur = v[cross_num][i];
        int curx = cur.X;
        int cury = cur.Y;
        if(right_upper[curx+cury] != 1 && left_upper[curx-cury+n-1] != 1){
            right_upper[curx+cury] = 1;
            left_upper[curx-cury+n-1] = 1;
            cur_cnt += 1;
            func(cross_num+1, cur_cnt);
            right_upper[curx+cury] = 0;
            left_upper[curx-cury+n-1] = 0;
            cur_cnt -= 1;
        }
    }
    func(cross_num+1, cur_cnt);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    //local variable
    cross_cnt = 2*n-1;
    for(int i = 0;i < cross_cnt;i++){
        vector<pair<int, int>> new_v;
        v.push_back(new_v);
    }
    // input board
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> bishop[i][j];
            if(bishop[i][j] == 1) v[i+j].push_back({i, j});
        }
    }
    // bfs & backtracking start
    func(0, 0);
    cout << max_cnt;
    return 0;
}