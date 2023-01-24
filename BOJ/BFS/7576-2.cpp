#include <iostream>
#include <queue>
#include <algorithm>
#define X first
#define Y second
using namespace std;

int board[1002][1002];
int dist[1002][1002];
int n, m;
int day = 0;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    queue<pair<int, int>> Q; //큐 선언
    fill(&dist[0][0], &dist[1001][1002], -2); //dist 배열 -2로 채우기
    cin >> m >> n; //m, n 입력받기
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> board[i][j];
            if(board[i][j] == 1){
                Q.push({i,j});
                dist[i][j] = 0;
            }
            else if(board[i][j] == 0){ //안 익은 토마토가 있는지 체크하기 위함
                dist[i][j] = -1;
            }
        }
    } //초기세팅 완료
    while(!Q.empty()){
        pair<int, int> cur = Q.front();
        Q.pop();
        for(int dir = 0;dir < 4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == -1 || dist[nx][ny] != -1) continue;
            Q.push({nx, ny});
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(dist[i][j] == -1){
                cout << -1;
                return 0;
            }
            day = max(day, dist[i][j]);
        }
    }
    cout << day;
    return 0;
}