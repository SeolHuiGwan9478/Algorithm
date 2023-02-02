#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;

char board[1002][1002]; //지도 배열
int fire[1002][1002]; //거리 기록 배열
int person[1002][1002];

int w, h, t; //넓이, 높이, 테스트케이스
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;//테스트 케이스 입력
    for(int i = 0;i < t;i++){
        queue<pair<int, int>> Q1; //Q1 선언 > 불의 이동
        queue<pair<int, int>> Q2; //Q2 선언 > 상근이의 이동
        fill(&board[0][0], &board[1001][1002], '\0');
        fill(&fire[0][0], &fire[1001][1002], -1); //fire 초기화
        fill(&person[0][0], &person[1001][1002], -1); //person 초기화
        cin >> w >> h; //넓이, 높이 입력
        for(int j = 0;j < h;j++){
            string map;
            cin >> map; //맵 입력
            for(int k = 0;k < w;k++){
                if(map[k] == '*'){
                    fire[j][k] = 0;
                    Q1.push({j, k});
                } //초기 세팅 완료
                else if(map[k] == '@'){
                    person[j][k] = 0;
                    Q2.push({j, k});
                }
                board[j][k] = map[k];
            }
        }

        //BFS
        while(!Q1.empty()){
            pair<int, int> cur = Q1.front();
            Q1.pop();
            for(int dir = 0;dir < 4;dir++){
                int nx = cur.X + dir[dx];
                int ny = cur.Y + dir[dy];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if(board[nx][ny] == '#' || fire[nx][ny] >= 0) continue;
                fire[nx][ny] = fire[cur.X][cur.Y] + 1;
                Q1.push({nx, ny});
            }
        }//불 번짐 시간 파악 완료

        //BFS
        bool isfind = false; //탈출구 찾았는지 확인용
        while(!Q2.empty()){
            pair<int, int> cur = Q2.front();
            Q2.pop();
            for(int dir = 0;dir < 4;dir++){
                int nx = cur.X + dir[dx];
                int ny = cur.Y + dir[dy];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w){
                    cout << person[cur.X][cur.Y] + 1 << "\n";
                    isfind = true;
                    break;
                }
                if(board[nx][ny] == '#' || person[nx][ny] >= 0) continue;
                if(fire[nx][ny] >= 0 && fire[nx][ny] <= person[cur.X][cur.Y] + 1) continue;
                person[nx][ny] = person[cur.X][cur.Y] + 1;
                Q2.push({nx, ny});
            }
            if(isfind) break;
        }
        if(!isfind) cout << "IMPOSSIBLE\n";
    }
}