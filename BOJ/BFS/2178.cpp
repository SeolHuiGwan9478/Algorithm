#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;

int board[102][102] = {0,};
int dist[102][102];
int n, m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int>> Q;
    fill(&dist[0][0], &dist[101][102], -1);
    
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        string road;
        cin >> road;
        for(int j = 0;j < m;j++) board[i][j] = road[j] - '0';
    }
    //초기 세팅
    dist[0][0] = 1;
    Q.push({0,0});

    //BFS 시작
    while(!Q.empty()){
        pair<int, int> cur = Q.front();
        Q.pop();
        for(int dir = 0;dir < 4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == 0 || dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    cout << dist[n-1][m-1];
}