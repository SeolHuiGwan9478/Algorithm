#include <iostream>
#include <queue>
using namespace std;

int dist[200000];
int n, k;
int dx[3] = {1, -1, 2};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //초기 세팅 완료
    fill(&dist[0], &dist[199999], -1);

    queue<int> Q;
    cin >> n >> k;
    Q.push(n);
    dist[n] = 0;

    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        for(int dir = 0;dir < 3;dir++){
            int nx = cur;
            if(dir == 2){
                nx *= dx[dir];
            }
            else{
                nx += dx[dir];
            }
            if(nx < 0 || nx >= 200000) continue;
            if(dist[nx] >= 0) continue;
            dist[nx] = dist[cur]+1;
            if(nx == k){
                cout << dist[k];
                return 0;
            }
            else{
                Q.push(nx);
            }
        }
    }
    cout << dist[k];
    return 0;
}