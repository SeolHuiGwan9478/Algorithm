#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> money) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // init
    int answer = 0;
    int n = money.size(); // 집 개수
    // dp function
    // dp[1]가 선택 여부에 따라 케이스가 나뉨 -> 일단 케이스가 분리되는 DP 문제
    // case 01: dp[1] = money[0] 일 때 -> 선택했을 때
    /*
    1번을 선택했기에 일단 선형 DP의 범위는 1~N-1
    dp[2] = dp[1]
    dp[i] = max(
        dp[i-1] -> d[i]를 미선택한 경우
        dp[i-2] + money[i-1] -> d[i]를 선택한 경우
    )
    */
    vector<int> dp1(1000001);
    dp1[1] = money[0];
    dp1[2] = money[0];
    for(int i = 3;i <= n-1;i++){
        dp1[i] = max(dp1[i-1], dp1[i-2] + money[i-1]);
    }
    // case 02: dp[1] = 0일 때 -> 미선택
    /*
    1번을 선택하지 않았기에 선형 DP의 범위는 2~N까지 -> N도 선택할 수 있기 때문이다.
    dp[2] = money[1]
    dp[i] = max(
        dp[i-1] -> d[i]를 미선택한 경우
        dp[i-2] + money[i-1] -> d[i]를 선택한 경우
    )
    */
    vector<int> dp2(1000001);
    dp2[1] = 0;
    dp2[2] = money[1];
    for(int i = 3;i <= n;i++){
        dp2[i] = max(dp2[i-1], dp2[i-2] + money[i-1]);
    }
    answer = max(dp1[n-1], dp2[n]);
    return answer;
}
