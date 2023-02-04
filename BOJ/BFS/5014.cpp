#include <iostream>
#include <queue>
using namespace std;

int floor[1000002];
int f, s, g, u, d;
int dx[2] = {0,};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> f >> s >> g >> u >> d;
    dx[0] = u; dx[1] = -d; //dx 설정 완료
    fill(&floor[0], &floor[1000002], -1); //층별 시간 세팅 완료

    //초기 세팅
    queue<int> Q;
    floor[s] = 0;
    Q.push(s);

    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        for(int dir = 0;dir < 2;dir++){
            int nx = cur + dx[dir];
            if(nx < 1 || nx > f) continue; //범위 오버
            if(floor[nx] >= 0) continue; //이미 방문한 층인 경우
            floor[nx] = floor[cur]+1;
            Q.push(nx);
        }
    }
    if(floor[g] != -1) cout << floor[g];
    else cout << "use the stairs";
}