#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    // 1. generate deque
    deque<int> deq_prior(priorities.begin(), priorities.end());
    sort(deq_prior.begin(), deq_prior.end(), greater<int>());
    deque<pair<int, bool>> deq; // value, mark
    for(int idx = 0;idx < priorities.size();idx++) {
        if(idx == location) deq.push_back({priorities[idx], true});
        else deq.push_back({priorities[idx], false});
    }
    // 2. queueing
    int target_value = deq_prior.front();
    while(!deq.empty()){
        // 2-1. 값 꺼내기
        pair<int, bool> cur_p = deq.front();
        // 2-2. 값 비교
        if(cur_p.first == target_value) {
            deq_prior.pop_front();
            deq.pop_front();
            answer += 1;
            if(cur_p.second){
                break;
            }else{
                target_value = deq_prior.front();
            }
        }else{
            deq.pop_front();
            deq.push_back(cur_p);
        }
    }
    return answer;
}
