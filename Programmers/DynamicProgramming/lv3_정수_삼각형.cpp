#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> triangle) {
    // init
    int answer = 0;
    int n = triangle.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1)); // dp_table
    // init value
    dp[1][1] = triangle[0][0];
    // 점화식
    /*
    1. 각 레벨 - 좌측: dp[x][1] = dp[x-1][1] + t[x-1][1-1];
    2. 각 레벨 - 우측: dp[x][x] = dp[x-1][x-1] + t[x-1][x-1];
    3. 나머지: dp[x][y] = max(dp[x-1][y-1] + t[x-1][y-1], dp[x-1][y] + t[x-1][y-1])
    */
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(i == 1 && j == 1) continue; // first func
            if(i < j) break;
            if(j == 1){ // left side
                dp[i][j] = dp[i-1][1] + triangle[i-1][0];
            }else if(i == j){
                dp[i][i] = dp[i-1][i-1] + triangle[i-1][i-1];
            }else{
                dp[i][j] = max(dp[i-1][j-1] + triangle[i-1][j-1], dp[i-1][j] + triangle[i-1][j-1]);
            }
        }
    }
    
    // answer setting
    int max_result = 0; // init
    for(int i = 1;i <= n;i++){
        if(dp[n][i] > max_result) max_result = dp[n][i];
    }
    
    answer = max_result;
    return answer;
}
