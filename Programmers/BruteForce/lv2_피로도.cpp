#include <bits/stdc++.h>

using namespace std;

int max_count = 0; // 최대 던전 수 변수

void count_dungeons(int r_k, int cur_count, vector<vector<int>> r_dungeons){
    int rd_size = r_dungeons.size();
    // base condition
    if(rd_size == 0) return;
    // main logic
    for(int idx = 0;idx < rd_size;idx++){
        vector<int> cur_dungeon = r_dungeons[idx];
        int min_p = cur_dungeon[0];
        int use_p = cur_dungeon[1];
        if(r_k < min_p) continue;
        r_k -= use_p; // 피로도 감소
        cur_count += 1;
        max_count = max(cur_count, max_count);
        // 남은 던전에서 현재 던전 제거
        r_dungeons.erase(r_dungeons.begin() + idx); // 제거
        count_dungeons(r_k, cur_count, r_dungeons);
        // 상태 되돌리기
        r_k += use_p;
        cur_count -= 1;
        r_dungeons.insert(r_dungeons.begin() + idx, cur_dungeon); // 복구
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // init
    int answer = -1;
    // call recursion func
    count_dungeons(k, 0, dungeons);
    answer = max_count;
    return answer;
}
