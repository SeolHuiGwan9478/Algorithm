#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int vis[201][201]; // visit array

int solution(int n, vector<vector<int>> computers) {
    // init
    int answer = 0;
    queue<pair<int, int>> Q;
    // main logic - 시작점이 2개인 문제
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(computers[i][j] != 1 || vis[i][j] != 0) continue;
            Q.push({i,j});
            vis[i][j] = 1;
            // main BFS logic
            while(!Q.empty()) {
                pair<int, int> cur = Q.front();
                Q.pop();
                for(int dir = 0;dir < n;dir++) {
                    int nx = cur.Y;
                    if(vis[nx][dir] == 1) continue;
                    if(computers[nx][dir] == 1){
                        Q.push({nx, dir}); // Q에 대입
                        vis[nx][dir] = 1; // 방문 기록
                    }
                }
            }
            answer += 1;
        }
    }
    return answer;
}
