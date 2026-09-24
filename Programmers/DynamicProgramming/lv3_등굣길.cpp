#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> d(101, vector<int>(101, 0)); // dp_table

int solution(int m, int n, vector<vector<int>> puddles) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // init
    int answer = 0;
    d[1][1] = 1; // home marking
    // main logic
    // d[i][j] = d[i][j-1] + d[i-1][j] = 왼쪽 경우의 수 + 위쪽 경우의 수
    for(vector<int> puddle : puddles){
        int i = puddle[1];
        int j = puddle[0];
        d[i][j] = -1; // water marking
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            int path_cnt = 0;
            if(i == 1 && j == 1) continue; // case 00: start point pass
            if(d[i][j] == -1) continue; // case 01: water marking pass
            if(j-1 >= 1 && d[i][j-1] != -1) {
                path_cnt += d[i][j-1];
            } // case 02: left out of range
            if(i-1 >= 1 && d[i-1][j] != -1){
                path_cnt += d[i-1][j];
            } // case 03: top out of range
            d[i][j] = path_cnt % 1000000007;
        }
    }
    answer = d[n][m];
    return answer;
}
