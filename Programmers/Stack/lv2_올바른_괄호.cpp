#include <bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    // base settings
    ios::sync_with_stdio(0);
    cin.tie(0);
    // init
    bool answer = true;
    stack<char> S;
    // main logic
    for(auto ch : s) {
        // base case
        if(S.size() == 0) S.push(ch);
        else if(ch == ')' && S.top() == '(') S.pop();
        else S.push(ch);
    }
    if(S.size() != 0) answer = false; 
    return answer;
}
