#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;

char boards[1002][1002];
int fire[1002][1002]; //불 번짐 시간
int jihun[1002][1002]; //지훈 방문 시간
int r, c; //행, 열 개수
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(&fire[0][0], &fire[1001][1002], -1); //fire 배열 -1로 채우기
    fill(&jihun[0][0], &jihun[1001][1002], -1); //jihun 배열 -1로 채우기

    queue<pair<int, int>> Q1; //지훈 큐
    queue<pair<int, int>> Q2; //불 큐

    cin >> r >> c; //행, 열 개수 입력받기
    for(int i = 0;i < r;i++){
        string board;
        cin >> board;
        for(int j = 0;j < c;j++){
            if(board[j] == 'J'){
                Q1.push({i,j});
                jihun[i][j] = 0;
            }
            else if(board[j] == 'F'){
                Q2.push({i,j});
                fire[i][j] = 0;
            }
            boards[i][j] = board[j];
        }
    } //초기 세팅 완료

    while(!Q2.empty()){
        pair<int, int> cur = Q2.front();
        Q2.pop();
        for(int dir = 0;dir < 4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue; //범위 벗어나면 continue
            if(boards[nx][ny] == '#' || fire[nx][ny] != -1) continue;
            Q2.push({nx, ny});
            fire[nx][ny] = fire[cur.X][cur.Y]+1;
        }
    } //불 퍼지는 시간 BFS 완료

    while(!Q1.empty()){
        pair<int, int> cur = Q1.front();
        Q1.pop();
        for(int dir = 0;dir < 4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c){
                cout << jihun[cur.X][cur.Y]+1;
                return 0;
            } //출구 찾을 경우 출력 후 종료
            if(boards[nx][ny] == '#' || jihun[nx][ny] != -1) continue;
            if(fire[nx][ny] != -1 && fire[nx][ny] <= jihun[cur.X][cur.Y]+1) continue;
            Q1.push({nx, ny});
            jihun[nx][ny] = jihun[cur.X][cur.Y]+1;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}