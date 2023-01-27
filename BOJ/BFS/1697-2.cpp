#include <iostream>
#include <queue>
using namespace std;

int dist[1000002];
int n, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    queue<int> Q;

    fill(&dist[0], &dist[100001], -1);
    cin >> n >> k;
    dist[n] = 0; 
    Q.push(n); //초기 세팅

    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        for(int nx : {cur+1, cur-1, 2*cur}){
            if(nx < 0 || nx > 100000) continue;
            if(dist[nx] >= 0) continue;
            dist[nx] = dist[cur]+1;
            Q.push(nx);
        }
    }
    cout << dist[k];
}