#include <bits/stdc++.h>

using namespace std;

vector<string> answer;
vector<bool> visited;

bool dfs(string cur, vector<vector<string>> tickets, int count) {
    if(count == tickets.size()) return true;
    for(int idx = 0;idx < tickets.size();idx++) {
        if(visited[idx]) continue; // 1-1. 시작점이 다를 경우
        if(tickets[idx][0] != cur) continue; 
        visited[idx] = true;
        answer.push_back(tickets[idx][1]);
        if(dfs(tickets[idx][1], tickets, count + 1)){
            return true;
        }
        visited[idx] = false;
        answer.pop_back();
    }
    return false;
}

bool compare(vector<string> a, vector<string> b){
    return a[1] < b[1];
}

vector<string> solution(vector<vector<string>> tickets) {
    // 1. init vars
    visited.assign(tickets.size(), false); // visited vector
    // 2. sort tickets
    sort(tickets.begin(), tickets.end(), compare);
    // 3. main logic
    answer.push_back("ICN");
    dfs("ICN", tickets, 0);
    return answer;
}
