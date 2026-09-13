#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> answers) {
    // init pattern
    vector<int> student_1 = {1,2,3,4,5};
    vector<int> student_2 = {2,1,2,3,2,4,2,5};
    vector<int> student_3 = {3,3,1,1,2,2,4,4,5,5};
    vector<int> s_count = {0,0,0};
    vector<int> answer;
    // main logic
    int s1_idx = 0;
    int s2_idx = 0;
    int s3_idx = 0;
    int s1_len = student_1.size();
    int s2_len = student_2.size();
    int s3_len = student_3.size();
    for(int idx = 0;idx < answers.size();idx++){
        int answer = answers[idx];
        int s1_answer = student_1[s1_idx % s1_len];
        int s2_answer = student_2[s2_idx % s2_len];
        int s3_answer = student_3[s3_idx % s3_len];
        if(s1_answer == answer) s_count[0] += 1;
        if(s2_answer == answer) s_count[1] += 1;
        if(s3_answer == answer) s_count[2] += 1;
        s1_idx++;
        s2_idx++;
        s3_idx++;
    }
    // find max answer count
    int max_value = *max_element(s_count.begin(), s_count.end());
    for(int i = 0;i < 3;i++){
        if(s_count[i] == max_value) answer.push_back(i+1);
    }
    return answer;
}
