#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> prices) {
    // init
    vector<int> answer(prices.size());
    stack<pair<int,int>> s;
    // main logic
    for(int idx = 0;idx < prices.size();idx++) {
        int price = prices[idx];
        // 1. base case
        pair<int, int> p = {idx, price};
        // 2. while loop 내에서 처음으로 가격이 작아졌는지 확인
        while(!s.empty()) {
            pair<int, int> top = s.top();
            if(top.second > price){
                s.pop();
                answer[top.first] = idx - top.first;
            }else{
                break;
            }
        }
        s.push(p);
    }
    // 잔여 작업: 끝까지 가격이 떨어지지 않는 것들
    int n = s.size();
    for(int idx = 0;idx < n;idx++){
        pair<int, int> p = s.top();
        s.pop();
        answer[p.first] = prices.size() - p.first - 1;
    }
    return answer;
}
