#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;

int board[1002][1002];
int n, m;
int days = 0, zerocnt = 0, isripe = 0;
bool ischange;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    queue<pair<int, int>> Q; //큐 선언
    cin >> m >> n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> board[i][j];
            if(board[i][j] == 1) Q.push({i,j}); //큐에 시작점 Push - 초기세팅
            else if(board[i][j] == 0) zerocnt++; //익어야 할 토마토 개수
        }
    }

    //모두 익은 상황 0 출력
    if(zerocnt == 0){ //익지 않은 토마토 개수가 0개 -> 모두 익은 경우
        cout << 0;
        return 0;
    }

    while(!Q.empty()){
        int cur_size = Q.size();
        ischange = false; //하나라도 토마토가 익었는지 체크하기 위한 변수
        for(int i = 0;i < cur_size;i++){
            pair<int, int> cur = Q.front();
            Q.pop();
            for(int dir = 0;dir < 4;dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(board[nx][ny] == -1 || board[nx][ny] == 1) continue;
                Q.push({nx, ny});
                board[nx][ny] = 1;
                ischange = true; //익었기에 true로 변경
                isripe++; //익은 토마토 개수
            }
        }
        if(ischange) days++; //하나라도 익었다면 day + 1 
    }

    if(zerocnt == isripe) cout << days;
    else cout << -1;
    return 0;
}