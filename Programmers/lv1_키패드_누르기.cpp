#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int cur_left[2] = {3,0}; // cur left hand pos
int cur_right[2] = {3,2}; // cur right hand pos
vector<int> left_btn = {1,4,7};
vector<int> mid_btn = {2,5,8,0};
vector<int> right_btn = {3,6,9};

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    for(int number : numbers){
        if(find(left_btn.begin(), left_btn.end(), number) != left_btn.end()){ // left
            answer += "L";
            int cur_y = number%3 == 0 ? 2 : number%3-1;
            int cur_x = (int)(number-cur_y-1)/3;
            cur_left[0] = cur_x;
            cur_left[1] = cur_y;
        }else if(find(mid_btn.begin(), mid_btn.end(), number) != mid_btn.end()){ // mi
            if(number == 0) number = 11;
            int target_y = number%3 == 0 ? 2 : number%3-1; // target btn pos y
            int target_x = (int)(number-target_y-1)/3; // target btn pos x
            int left_dist = abs(cur_left[0] - target_x) + abs(cur_left[1] - target_y);
            int right_dist = abs(cur_right[0] - target_x) + abs(cur_right[1] - target_y);
            if(left_dist < right_dist){
                answer += "L";
                cur_left[0] = target_x;
                cur_left[1] = target_y;
            }else if(left_dist > right_dist){
                answer += "R";
                cur_right[0] = target_x;
                cur_right[1] = target_y;
            }else{
                if(hand == "right"){
                    answer += "R";
                    cur_right[0] = target_x;
                    cur_right[1] = target_y;
                }else{
                    answer += "L";
                    cur_left[0] = target_x;
                    cur_left[1] = target_y;
                }
            }
        }else if(find(right_btn.begin(), right_btn.end(), number) != right_btn.end()){ // right
            answer += "R";
            int cur_y = number%3 == 0 ? 2 : number%3-1;
            int cur_x = (int)(number-cur_y-1)/3;
            cur_right[0] = cur_x;
            cur_right[1] = cur_y;
        }
    }
    return answer;
}