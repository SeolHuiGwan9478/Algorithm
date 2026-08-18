#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    // init
    vector<int> answer;
    queue<int> min_day;
    // Queue setting
    for(int idx = 0;idx < progresses.size();idx++){
        // 1. get data
        int progress = progresses[idx];
        int speed = speeds[idx];
        // 2. calc rest value
        int rest_progress = 100 - progress;
        int rest_day = rest_progress/speed;
        if(rest_progress%speed != 0) rest_day += 1;
        min_day.push(rest_day);
    }
    // 2. 메인 로직
    // 2-1. init setting
    int day = 0;
    int prev_min_day = min_day.front(); // 기준이 될 값, 초기값은 가장 앞의 값
    while(!min_day.empty()) { // 남은 날이 빌 때까지 진행
        int cur_min_day = min_day.front(); // 가장 앞의 값을 가져온다.
        if(prev_min_day >= cur_min_day) { // 동일 값, 기준 값보다 작은값이 나오면 한번에 처리 가능
            day += 1;
            min_day.pop();
            if(min_day.empty()) answer.push_back(day); // 기준값이 마지막일 경우를 확인
        }else{ // 그것이 아니라면 한번에 처리한 값을 Push 하고 -> 기준값 변경
            answer.push_back(day);
            day = 0;
            prev_min_day = cur_min_day;
        }
    }
    return answer;
}
