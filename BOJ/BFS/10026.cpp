#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;

char board[102][102]; //그림판
int vis[102][102] = {0,};//방문 체크
int n; //행, 렬 크기 N
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void bfs(){
    char start = '\0'; //start 값 선언
    int section = 0; //section 개수
    queue<pair<int, int>> Q;

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(vis[i][j] == 0){
                start = board[i][j];
                vis[i][j] = 1;
                Q.push({i, j});
                section += 1; //일반인 섹션 추가
            }
            else continue;
            while(!Q.empty()){
                pair<int, int> cur = Q.front();
                Q.pop();
                for(int dir = 0;dir < 4;dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(board[nx][ny] != start || vis[nx][ny] == 1) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
        }
    }
    cout << section << ' ';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n; //N 입력
    
    for(int i = 0;i < n;i++){
        string color;
        cin >> color;
        for(int j = 0;j < n;j++) board[i][j] = color[j];
    }//board 입력 완료

    //일반인 섹션 계산
    bfs();

    //적록색약 환자 섹션 계산
    fill(&vis[0][0], &vis[101][102], 0); //vis 배열 초기화
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(board[i][j] == 'G') board[i][j] = 'R';
        }
    }
    bfs();
    return 0;
}