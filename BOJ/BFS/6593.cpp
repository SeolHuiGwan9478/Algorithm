#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

char board[32][32][32]; //빌딩 배열
int dist[32][32][32];
int l, r, c; //층수, 행, 열
int tx, ty, tz; //탈출구 x,,y,z 좌표
int dx[6] = {1,0,-1,0,0,0}; //dx,dy,dz
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    queue<tuple<int, int, int>> Q;
    while(true){
        cin >> l >> r >> c; //l, r, c 입력
        if(l == 0 && r == 0 & c == 0) break; //종료 조건
        fill(&dist[0][0][0], &dist[31][31][32], -1); //dist 배열 초기화
        for(int i = 0;i < l;i++){
            for(int j = 0;j < r;j++){
                for(int k = 0;k < c;k++){
                    cin >> board[i][j][k];
                    if(board[i][j][k] == 'S'){
                        dist[i][j][k] = 0;
                        Q.push({i, j, k});
                    }
                    else if(board[i][j][k] == '#') dist[i][j][k] = -2;
                    else if(board[i][j][k] == 'E'){
                        tx = j;
                        ty = k;
                        tz = i;
                    }
                }
            }
        }
        
        //BFS
        while(!Q.empty()){
            int curx, cury, curz;
            tie(curz, curx, cury) = Q.front(); //Q에서 꺼내기
            Q.pop();
            for(int dir = 0;dir < 6;dir++){
                int nx = curx + dx[dir];
                int ny = cury + dy[dir];
                int nz = curz + dz[dir];
                if(nx < 0 || nx >= r || ny < 0 || ny >= c || nz < 0 || nz >= l) continue;
                if(board[nz][nx][ny] == '#' || dist[nz][nx][ny] >= 0) continue;
                dist[nz][nx][ny] = dist[curz][curx][cury]+1;
                Q.push({nz, nx, ny});
            }
        }
        if(dist[tz][tx][ty] == -1) cout << "Trapped!\n";
        else cout << "Escaped in " << dist[tz][tx][ty] << " minute(s).\n";
    }
}