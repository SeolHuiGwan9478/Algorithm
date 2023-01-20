#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second

int board[502][502]; //말 그대로 그래프를 나타내는 판을 의미
bool vis[502][502] = {0, }; //방문했는지 체크하는 배열
int n = 7, m = 10; //n 은 행, m은 열 개수
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int,int>> Q;
    //초기 세팅
    vis[0][0] = 1;
    Q.push({0,0});

    while(!Q.empty()){ //큐가 빌 때까지
        pair<int, int> cur = Q.front(); //front 값 가져오기
        Q.pop(); //큐에서 front 제거
        cout << "(" << cur.X << ", " << cur.Y << ") -> ";
        for(int dir = 0;dir < 4;dir++){
            int nx = cur.X + dx[dir]; //상하좌우의 x 좌표 구하기
            int ny = cur.Y + dy[dir]; //상하좌우의 y 좌표 구하기
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; //다차원 배열 내의 값인지 continue
            if(vis[nx][ny] == 1 || board[nx][ny] == 0) continue; //파란색 칸이 아니거나(* 빨간색) 또는 방문한 곳일 때 continue
            vis[nx][ny] = 1; //위의 두 if문을 통과했다면 방문했다고 표시
            Q.push({nx,ny}); //큐에 push
        }
    }
}