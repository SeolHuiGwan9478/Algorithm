#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int dist[10000000] = {0, };
int dx[2] = {1, 2};

int solution(vector<int> numbers, int target) {
    // 1. base setting
    int answer = 0;
    queue<pair<int, int>> Q;
    Q.push({0, 0});
    dist[0] = 0;
    // 2. 1차원 BFS 로직 -> dir은 2*i+1, 2*i+2
    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); // idx, numbers_idx
        Q.pop();
        if(cur.Y == numbers.size()){
            if(dist[cur.X] == target) answer += 1;
            continue;
        }
        int cur_number = numbers[cur.Y];
        for(int dir = 0; dir < 2; dir++) {
            int nx = 2 * cur.X + dx[dir];
            if(dir == 0) dist[nx] = dist[cur.X] + cur_number;
            else if(dir == 1) dist[nx] = dist[cur.X] - cur_number;
            Q.push({nx, cur.Y+1});
        }
    }
    return answer;
}
