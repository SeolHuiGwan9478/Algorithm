#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    // init 
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> answer;
    // main logic
    for(int num : arr) {
        if(answer.empty()) {
            answer.push_back(num);
            continue;
        }
        int top = answer.back();
        if(top != num) answer.push_back(num);
    }
    return answer;
}
