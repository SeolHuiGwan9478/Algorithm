#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;

int dist[302][302];
int l, tcnt; //격자 크기, 테스트케이스 개수
int sx, sy, tx, ty; //시작 x, 시작 y, 목표 x, 목표 y
int dx[8] = {2,1,-1,-2,-2,-1,1,2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int>> Q;

    cin >> tcnt; //테케 입력
    for(int i = 0;i < tcnt;i++){
        cin >> l >> sx >> sy >> tx >> ty;
        fill(&dist[0][0], &dist[301][302], -1);
        dist[sx][sy] = 0; //시작점 거리 0
        Q.push({sx, sy});

        //BFS
        while(!Q.empty()){
            pair<int, int> cur = Q.front();
            Q.pop();
            for(int dir = 0;dir < 8;dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
                if(dist[nx][ny] >= 0) continue;
                dist[nx][ny] = dist[cur.X][cur.Y]+1;
                Q.push({nx, ny});
            }
        }
        cout << dist[tx][ty] << "\n";
    }

    return 0;
}