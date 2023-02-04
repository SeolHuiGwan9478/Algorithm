#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define X first
#define Y second
using namespace std;

int board[102][102] = {0, }; //모눈종이
int vis[102][102] = {0, }; //방문 배열
int m, n, k; //세로, 가로, 사각형 개수
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int cnt = 0;
vector<int> area;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> k;
    for(int i = 0;i < k;i++){
        int lx,ly,rx,ry; //좌측하단 xy, 우측상단 xy
        cin >> lx >> ly >> rx >> ry;
        for(int j = 0;j < ry-ly;j++){
            for(int k = 0;k < rx-lx;k++){
                board[ly+j][lx+k] = 1;
            }
        } //board 채우기 완료
    }

    queue<pair<int, int>> Q;
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){ //시작점 찾기
            if(board[i][j] == 0 && vis[i][j] == 0){
                vis[i][j] = 1;
                Q.push({i, j});
                cnt += 1;
                area.push_back(1);
            }
            else continue;
            //BFS
            while(!Q.empty()){
                pair<int, int> cur = Q.front();
                Q.pop();
                for(int dir = 0;dir < 4;dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if(board[nx][ny] == 1 || vis[nx][ny] == 1) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                    area[cnt-1] += 1; //넓이 계산
                }
            }
        }
    }
    //영역 개수, 넓이 출력
    cout << cnt << "\n";
    sort(area.begin(), area.end()); //오름차순 정렬
    for(int i = 0;i < cnt;i++){
        cout << area[i] << " ";
    }
}