// https://www.acmicpc.net/problem/14891
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <cmath>
using namespace std;

vector<deque<int>> wheels;
int k, wheel_no, direction;
int score = 0;
const int right_access = 2;
const int left_access = 6;

// 시계 방향 회전
void right_rotation(int wheel_no){
    int back = wheels[wheel_no-1].back();
    wheels[wheel_no-1].pop_back();
    wheels[wheel_no-1].push_front(back);
}

// 반시계 방향 회전
void left_rotation(int wheel_no){
    int front = wheels[wheel_no-1].front();
    wheels[wheel_no-1].pop_front();
    wheels[wheel_no-1].push_back(front);
}

void wheels_rotation(){
    int is_visited[4] = {0,0,0,0};
    int rotation_dir[4] = {0,0,0,0};
    int dx[2] = {-1, 1};
    cin >> wheel_no >> direction;

    queue<pair<int,int>> Q;
    Q.push({wheel_no, direction});
    is_visited[wheel_no-1] = 1;
    rotation_dir[wheel_no-1] = direction;
    while(!Q.empty()){
        pair<int, int> cur = Q.front();
        Q.pop();
        for(int i = 0;i < 2;i++){
            int next_wheel = cur.first + dx[i];
            int next_dir = cur.second * (-1);
            if(next_wheel-1 < 0 || next_wheel-1 >= 4) continue;
            if(is_visited[next_wheel-1] == 1) continue;
            // 왼쪽 톱니바퀴 같은지 확인
            if(i == 0 && (wheels[cur.first-1][left_access] == wheels[next_wheel-1][right_access])){
                continue;
            }
            // 오른쪽 톱니바퀴 같은지 확인
            if(i == 1 && (wheels[cur.first-1 ][right_access] == wheels[next_wheel-1][left_access])){
                continue;
            }
            Q.push({next_wheel, next_dir});
            is_visited[next_wheel-1] = 1;
            rotation_dir[next_wheel-1] = next_dir;
        }
    }
    for(int i = 0;i < 4;i++){
        if(rotation_dir[i] == 1){
            right_rotation(i+1);
        }else if(rotation_dir[i] == -1){
            left_rotation(i+1);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // input wheel status
    for(int i = 0;i < 4;i++){
        string wheel_status;
        cin >> wheel_status;
        deque<int> wheel;
        for(int j = 0;j < 8;j++){
            wheel.push_back(wheel_status[j] - '0');
        }
        wheels.push_back(wheel);
    }

    // input rotation count
    cin >> k;
    // input wheel number & direction
    // direction 1: right, -1: left
    for(int i = 0;i < k;i++){
        wheels_rotation();
    }
    // sum of wheel score
    for(int i = 0;i < 4;i++){
        if(wheels[i][0] == 1){
            score += pow(2,i);
        }
    }
    cout << score;
}