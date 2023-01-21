#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;

int board[502][502] = {0,};
bool vis[502][502] = {0,};
int n, m, max_width = 0;
int cnt = 0;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void BFS(int x, int y){
    queue<pair<int,int>> Q;
    int width = 1;
    //초기 세팅
    vis[x][y] = 1;
    Q.push({x, y});

    while(!Q.empty()){
        pair<int, int> cur = Q.front();
        Q.pop();
        for(int dir = 0;dir < 4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == 0 || vis[nx][ny] == 1) continue;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
            width++;
        }
    }
    if(width > max_width) max_width = width;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //행(세로), 열(가로) 크기 입력
    cin >> n >> m;
    for(int i = 0;i < n;i++){ //그림 입력받기
        for(int j = 0;j < m;j++) cin >> board[i][j];
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(board[i][j] == 0 || vis[i][j] == 1) continue;
            int x = i, y = j;
            BFS(i, j);
            cnt++;
        }
    }
    cout << cnt << '\n';
    cout << max_width << '\n';
    return 0;
}