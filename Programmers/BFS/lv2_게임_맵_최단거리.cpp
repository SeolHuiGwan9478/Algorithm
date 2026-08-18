#include<bits/stdc++.h>

#define X first
#define Y second

using namespace std;

// * dx, dy 좌표 셋팅
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dist[101][101]; // visitor array

int solution(vector<vector<int>> maps)
{
    // 1. BFS settings
    int answer = 0;
    fill(&dist[0][0], &dist[100][101], -1); // * fill dist array -> -1
    int n = maps.size(); // row size
    int m = maps[0].size(); // column size
    queue<pair<int, int>> Q;
    Q.push({0,0}); // 시작 위치 처리
    dist[0][0] = 1;
    
    while(!Q.empty()){
        pair<int, int> cur = Q.front();
        Q.pop();
        for(int dir = 0;dir < 4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            // * map 이 막혀있거나 또는 이미 방문했거나
            if(maps[nx][ny] == 0 || dist[nx][ny] > 0) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1; // 방문 체킹
            Q.push({nx, ny}); // Queue에 푸쉬
        }
    }
    answer = dist[n-1][m-1];
    return answer;
}
