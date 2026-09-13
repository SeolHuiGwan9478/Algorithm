#include<bits/stdc++.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // init
    vector<int> answer;
    int sqrt_yellow = sqrt(yellow);
    // main logic
    for(int n = 1;n <= sqrt_yellow;n++){
        if(yellow % n == 0){ // yellow n,m checking
            int m = yellow/n;
            if(2*(n+m+2) == brown){
                answer.push_back(max(n,m)+2);
                answer.push_back(min(n,m)+2);
            }
        }
    } 
    return answer;
}
