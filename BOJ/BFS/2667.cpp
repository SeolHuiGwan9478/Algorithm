#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define X first
#define Y second
using namespace std;

int board[27][27];
int vis[27][27] = {0, };
int n; //가로, 세로 길이
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int cnt = 0; //단지 수
vector<int> home; //단지 수 저장할 벡터

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0;i < n;i++){
        string raw;
        cin >> raw;
        for(int j = 0;j < n;j++){
            board[i][j] = raw[j] - '0';
        }
    } //지도 세팅 완료
    //BFS
    queue<pair<int, int>> Q;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(board[i][j] == 1 && vis[i][j] == 0){
                vis[i][j] = 1;
                Q.push({i, j});
                cnt += 1;
                home.push_back(1);
            }
            else continue;
            while(!Q.empty()){
                pair<int, int> cur = Q.front();
                Q.pop();
                for(int dir = 0;dir < 4;dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(board[nx][ny] == 0 || vis[nx][ny] == 1) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                    home[cnt-1] += 1;
                }
            }
        }
    }
    cout << cnt << "\n";
    sort(home.begin(), home.end());
    for(int i = 0;i < cnt;i++){
        cout << home[i] << "\n";
    }
}