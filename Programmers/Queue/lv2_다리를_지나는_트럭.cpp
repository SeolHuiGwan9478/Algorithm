#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    // 1. init
    deque<int> truck_weights_deq(
        truck_weights.begin(), 
        truck_weights.end()
    );
    vector<int> v(bridge_length);
    int answer = 0;
    // 2. main logic
    // 2-1. 초기 셋팅
    answer += 1;
    // 2-2. generate deque
    int cur_value = truck_weights_deq.front(); // 첫번째 값
    truck_weights_deq.pop_front(); // 첫번째 값만 빼기
    v[bridge_length-1] = cur_value;
    deque<int> deq(v.begin(), v.end());
    // 2-3. sum - 전체 무게
    int sum = cur_value;
    while(!deq.empty()){
        cur_value = deq.front();
        deq.pop_front();
        // 전체 무게 계산
        sum -= cur_value;
        // 3-1. 새 값 넣기
        // 3-2. 넣을 값이 있는지부터 확인
        if(!truck_weights_deq.empty()){
            int cur_truck_weight = truck_weights_deq.front();
            if(sum + cur_truck_weight > weight){
                deq.push_back(0);
            }else{
                deq.push_back(cur_truck_weight);
                sum += cur_truck_weight;
                truck_weights_deq.pop_front();
            }
        }
        answer += 1; 
    }
    return answer;
}
