// https://www.acmicpc.net/problem/2579
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int step_num;
vector<int> scores;
int d[301][2] = {0,};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> step_num;
    for(int i = 0;i < step_num;i++){
        int score;
        cin >> score;
        scores.push_back(score);
    }
    // init value
    d[1][0] = scores[0];
    d[1][1] = scores[0];
    d[2][0] = scores[1];
    d[2][1] = scores[0] + scores[1];
    // fill dp table
    for(int i = 3;i <= step_num;i++){
        d[i][0] = *max_element(d[i-2], d[i-2] + 2) + scores[i-1];
        d[i][1] = d[i-1][0] + scores[i-1];
    }
    cout << *max_element(d[step_num], d[step_num] + 2);
}