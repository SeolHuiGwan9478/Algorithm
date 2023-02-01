#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int board[102][102][102]; //토마토 판
int dist[102][102][102]; //방문 체크
int n, m, h; //행, 열, 높이
int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,-1,1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<vector<int>> Q;
    fill(&dist[0][0][0], &dist[101][101][102], -2);
    cin >> m >> n >> h; //행, 열, 높이 입력
    for(int i = 0;i < h;i++){
        for(int j = 0;j < n;j++){
            for(int k = 0;k < m;k++){
                cin >> board[i][j][k]; //토마토 세팅
                if(board[i][j][k] == 1){
                    vector<int> v = {i, j, k};
                    dist[i][j][k] = 0;
                    Q.push(v);
                }
                else if(board[i][j][k] == 0){
                    dist[i][j][k] = -1;
                }
            }
        }
    }//토마토 세팅 완료
    while(!Q.empty()){
        vector<int> cur = Q.front();
        Q.pop();
        for(int dir = 0;dir < 6;dir++){
            int nx = cur[1] + dx[dir];
            int ny = cur[2] + dy[dir];
            int nz = cur[0] + dz[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
            if(board[nz][nx][ny] == -1 || dist[nz][nx][ny] >= 0) continue;
            vector<int> v = {nz, nx, ny};
            dist[nz][nx][ny] = dist[cur[0]][cur[1]][cur[2]]+1;
            Q.push(v);
        }
    }

    int days = 0;
    for(int i = 0;i < h;i++){
        for(int j = 0;j < n;j++){
            for(int k = 0;k < m;k++){
                if(dist[i][j][k] == -1){
                    cout << -1;
                    return 0;
                }
                days = max(days, dist[i][j][k]);
            }
        }
    }
    cout << days;
}