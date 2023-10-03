// https://www.acmicpc.net/problem/11559
#include <iostream>
#include <queue>
#include <vector>
#define X first;
#define Y second;
using namespace std;

// global variable
char board[12][6]; // game board
int is_visited[12][6];
int bomb_cnt = 0; // 연쇄 횟수
bool is_change; // 뿌요 더졌는지에 대한 여부
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue<pair<int, int>> Q; // queue for bfs

void puyo_bfs(){
    vector<pair<int, int>> checked_puyo; // 확인된 뿌요를 저장할 벡터
    while(!Q.empty()){
        pair<int, int> cur = Q.front();
        int curx = cur.X; // 현재 x 좌표
        int cury = cur.Y; // 현재 y 좌표
        char cur_color = board[curx][cury]; // 현재 색깔
        Q.pop();
        checked_puyo.push_back({curx, cury}); // 확인된 뿌요 추가
        for(int i = 0;i < 4;i++){
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if(nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
            if(board[nx][ny] == '.' || board[nx][ny] != cur_color || is_visited[nx][ny] == 1) continue;
            is_visited[nx][ny] = 1; // 방문 표시
            Q.push({nx, ny}); // Q 대입
        }
    }
    if(checked_puyo.size() >= 4){ // 연결된 뿌요가 4개 이상이면
        is_change = true; // 터졌다는 것을 알림
        for(auto puyo : checked_puyo){
            int nx = puyo.X;
            int ny = puyo.Y;
            board[nx][ny] = '.'; // 터진 뿌요 자리 '.'으로 변경
        }
    }
    return;
}

void puyo_down(){
    for(int j = 0;j < 6;j++){
        for(int i = 11;i >= 0;i--){
            if(board[i][j] == '.') continue; // 빈칸은 continue
            char cur_puyo = board[i][j]; // 이동시킬 뿌요 선택
            int nxt_row = i + 1; // 다음 행 번호
            while(true){
                if(nxt_row > 11 || board[nxt_row][j] != '.') break; // 게임 보드 끝 또는 다른 뿌요를 만났을 때
                board[nxt_row-1][j] = '.'; // 기존 뿌요 제거
                board[nxt_row][j] = cur_puyo; // 한칸 이동
                nxt_row++; // 다음 행 증가
            }
        } 
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0;i < 12;i++){
        for(int j = 0;j < 6;j++){
            cin >> board[i][j];
        }
    } // input complete

    while(true){
        is_change = false;
        fill(&is_visited[0][0], &is_visited[11][6], 0); // initializing is_visited arr
        // bfs 시작점 찾기
        for(int i = 0;i < 12;i++){
            for(int j = 0;j < 6;j++){
                if(board[i][j] != '.' && is_visited[i][j] != 1){
                    Q.push({i, j});
                    is_visited[i][j] = 1;
                    puyo_bfs(); // bfs 호출
                }
            }
        }
        if(!is_change) break; // 터진 것이 없을 경우 멈춤
        // 아래로 떨어뜨리기
        puyo_down();
        bomb_cnt++;
    }
    cout << bomb_cnt;
    return 0;
   // 1. bfs를 통해 모든 뿌요 확인, 터진 뿌요 구역 '.'으로 변경
   // 2. 아래로 떨어뜨리기
   // 3. 변경이 하나라도 있다면 1~2 다시 반복
   // (* flood fill 문제와 같이 연결되어 있는 구역을 확인해야 하므로 bfs를 사용하기로 결정)
}