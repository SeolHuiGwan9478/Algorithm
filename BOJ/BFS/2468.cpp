#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define X first
#define Y second
using namespace std;

int board[102][102] = {0, }; //높이 배열
int vis[102][102];//방문 배열
int n; //가로, 세로 길이
int max_rain = 0; //최대 지역 높이
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
vector<int> areas;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> board[i][j];
            max_rain = max(max_rain, board[i][j]);
        }
    }// 지역 높이 정보 입력 완료

    queue<pair<int, int>> Q;
    for(int rain = 0;rain <= max_rain;rain++){
        areas.push_back(0);
        fill(&vis[0][0], &vis[101][102], 0); //vis 배열 초기화
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(board[i][j] > rain && vis[i][j] == 0){
                    //시작점 찾기
                    vis[i][j] = 1; //방문 표시
                    Q.push({i, j}); //Q에 넣기
                    areas[rain] += 1; //영역 개수 증가
                }
                else continue;
                //BFS
                while(!Q.empty()){
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    for(int dir = 0;dir < 4;dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if(board[nx][ny] <= rain || vis[nx][ny] == 1) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
            }
        }
    }
    cout << *max_element(areas.begin(), areas.end());
}