// https://www.acmicpc.net/problem/1941
#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;

// global variable
char seats[5][5];
int select_seats[5][5];
int is_visited[5][5];
int students[25] = {0,};
int combination[25] = {0,};
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int case_cnt = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // input seats
    for(int i = 0;i < 5;i++){
        string seat;
        cin >> seat;
        for(int j = 0;j < 5;j++) seats[i][j] = seat[j];
    }
    // fill students number
    for(int i = 0;i < 25;i++) students[i] = i+1;
    // fill combination arr for combination operation
    fill(combination+7, combination+25, 1);
    // 조합 구하기
    do{
        queue<pair<int, int>> Q;
        // initialize select_seats arr & is_visited arr
        fill(&select_seats[0][0], &select_seats[4][5], 0);
        fill(&is_visited[0][0], &is_visited[4][5], 0);
        // select students 7
        int tmp = 0, s_cnt = 0;
        int s_x, s_y;
        for(int i = 0;i < 25;i++){
            if(combination[i] == 0){
                int x = i/5;
                int y = i%5;
                if(seats[x][y] == 'S') s_cnt += 1;
                select_seats[x][y] = 1;
                // push starter point into Q
                if(tmp == 0){
                    // find bfs starter point
                    s_x = x;
                    s_y = y;
                    tmp += 1;
                }
            }
        }
        if(s_cnt >= 4){
            // bfs 초기 세팅
            is_visited[s_x][s_y] = 1;
            Q.push({s_x, s_y});
            // bfs 시작
            int cnt7 = 0;
            while(!Q.empty()){
                pair<int, int> cur = Q.front();
                Q.pop();
                cnt7 += 1;
                if(cnt7 == 7) case_cnt += 1;
                for(int j = 0;j < 4;j++){
                    int nx = cur.X + dx[j];
                    int ny = cur.Y + dy[j];
                    if(nx < 0 || nx > 4 || ny < 0 || ny > 4) continue;
                    if(is_visited[nx][ny] == 1 || select_seats[nx][ny] == 0) continue;
                    is_visited[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
        }
    }while(next_permutation(combination, combination+25));
    cout << case_cnt;
    return 0;
}