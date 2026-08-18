#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

bool is_changeable(string origin, string target, int idx, int n){
    // 1. sub string
    string origin_pre = origin.substr(0, idx);
    string origin_post = (idx+1 == n) ? "" : origin.substr(idx+1);
    string target_pre = target.substr(0, idx);
    string target_post = (idx+1 == n) ? "" : target.substr(idx+1);
    // 2. validation
    if(origin_pre == target_pre && origin_post == target_post) return true;
    return false;
}

int solution(string begin, string target, vector<string> words) {
    // init
    int answer = 0;
    int n = begin.length();
    int visited[51] = {0,};
    queue<pair<string, int>> Q; // 문자열, 시간
    Q.push({begin, 0});
    while(!Q.empty()) {
        pair<string, int> cur = Q.front();
        string cur_str = cur.X;
        int cur_time = cur.Y;
        if(cur_str == target){
            answer = cur_time;
            break;
        }
        Q.pop();
        for(int dir = 0;dir < n;dir++){
            for(int idx = 0;idx < words.size();idx++){
                string word = words[idx];
                if(visited[idx] == 1) continue;
                bool changeable = is_changeable(cur_str, word, dir, n);
                if(changeable){
                    Q.push({word, cur_time+1});
                    visited[idx] = 1;
                }
            }
        }
        
    }
    return answer;
}
