// https://www.acmicpc.net/problem/18809
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define X first;
#define Y second;
using namespace std;

// glboal variable
int n, m, g, r;
int garden[50][50];
int time_board[50][50];
char compo_board[50][50]; // G : green, R : red, F : flower, E : empty
vector<pair<int, int>> is_possible;
vector<int> combination;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int max_flower = -1; // 최대 꽃의 개수

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> g >> r;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> garden[i][j];
            if(garden[i][j] == 2) is_possible.push_back({i, j});
        }
    }
    // for green liquid -> 0, for red liquid 0 -> 1, other -> 2
    for(int i = 0;i < g;i++) combination.push_back(0);
    for(int i = 0;i < r;i++) combination.push_back(1);
    for(int i = 0;i < is_possible.size()-g-r;i++) combination.push_back(2);
    // 초록색, 빨간색 배양액 조합 구하기
    do{
        // local variable
        queue<pair<int, int>> Q;
        int cur_i, cur_j;
        // initialize arr
        fill(&time_board[0][0], &time_board[49][50], -1);
        fill(&compo_board[0][0], &compo_board[49][50], 'E');
        // bfs setting
        for(int i = 0;i < combination.size();i++){
            if(combination[i] == 0){ // green liquid
                cur_i = is_possible[i].X;
                cur_j = is_possible[i].Y;
                time_board[cur_i][cur_j] = 0;
                compo_board[cur_i][cur_j] = 'G';
                Q.push({cur_i, cur_j});
            }else if(combination[i] == 1){ // red liquid
                cur_i = is_possible[i].X;
                cur_j = is_possible[i].Y;
                time_board[cur_i][cur_j] = 0;
                compo_board[cur_i][cur_j] = 'R';
                Q.push({cur_i, cur_j});
            }
        }
        // flower cnt
        int cur_flower = 0;
        while(!Q.empty()){
            // local variable for bfs
            pair<int, int> cur = Q.front();
            int cur_x = cur.X;
            int cur_y = cur.Y;
            int cur_time = time_board[cur_x][cur_y]; // 현재 보고있는 것의 시간
            char cur_compo = compo_board[cur_x][cur_y]; // 현재 보고있는 것의 색
            Q.pop();
            if(cur_compo == 'F') continue;
            for(int i = 0;i < 4;i++){
                int nx = cur_x + dx[i];
                int ny = cur_y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // nx, ny가 범위를 벗어난 경우
                if(garden[nx][ny] == 0) continue; // 호수인 경우
                if(time_board[nx][ny] == -1){ // 방문하지 않은 경우
                    time_board[nx][ny] = cur_time + 1;
                    compo_board[nx][ny] = cur_compo;
                    Q.push({nx, ny});
                }
                // 동일 시간대에 배양된 액상인 경우 & 다른 색상의 액상인 경우 -> F(꽃)으로 변환
                else if(time_board[nx][ny] == cur_time + 1){
                    if((compo_board[nx][ny] == 'R' && cur_compo == 'G') || (compo_board[nx][ny] == 'G' && cur_compo == 'R')){
                        //cout << "compo_board :" << compo_board[nx][ny] << '\n';
                        //cout << "cur_compo :" << cur_compo << '\n';
                        compo_board[nx][ny] = 'F';
                        cur_flower += 1;
                    }
                    else continue; // 다른 경우
                }
                else continue; // 다른 수인 경우
            }
        }
        if(cur_flower > max_flower) max_flower = cur_flower;
    }while(next_permutation(combination.begin(), combination.end()));
    cout << max_flower;
    return 0;
}