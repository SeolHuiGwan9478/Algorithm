#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;

int board[52][52];
int vis[52][52];
int n, m, t, k, x, y;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int,int>> Q;

    cin >> t;
    for(int i = 0;i < t;i++){
        fill(&board[0][0], &board[51][52], 0);
        fill(&vis[0][0], &vis[51][52], 0);
        int cnt = 0;
        cin >> m >> n >> k;
        for(int j = 0;j < k;j++){
            cin >> x >> y;
            board[y][x] = 1;
        }//board 채우기
        for(int i2 = 0;i2 < n;i2++){
            for(int j2 = 0;j2 < m;j2++){
                if(board[i2][j2] == 1 && vis[i2][j2] == 0){
                    vis[i2][j2] = 1;
                    Q.push({i2,j2});
                    cnt += 1;
                }
                else continue;
                while(!Q.empty()){
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    for(int dir = 0;dir < 4;dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >=m) continue;
                        if(board[nx][ny] == 0 || vis[nx][ny] == 1) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}