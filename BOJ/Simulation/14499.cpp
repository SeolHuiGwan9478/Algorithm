#include <iostream>
#include <vector>
#include <deque>
using namespace std;

const int top_index = 1;
int n, m;
int x, y;
int k;
vector<vector<int>> map;
deque<int> row_dice(3);
deque<int> column_dice(4);

void copy_func(){
    // map이 0일 때
    if(map[x][y] == 0){
        map[x][y] = column_dice.back();
    }else{
        column_dice.pop_back();
        column_dice.push_back(map[x][y]);
        map[x][y] = 0;
    }
}

void rolling_column(int dir){
    if(dir == 3){
        int after_x = x - 1;
        if(after_x < 0 || after_x >= n) return;
        else x = after_x; 

        int next_top = column_dice[2];
        int front = column_dice.front();
        // rolling column
        column_dice.pop_front();
        column_dice.push_back(front);
        // update row
        row_dice[top_index] = next_top;
    }else if(dir == 4){
        int after_x = x + 1;
        if(after_x < 0 || after_x >= n) return;
        else x = after_x; 

        int next_top = column_dice.front();
        int back = column_dice.back();
        // rolling column
        column_dice.pop_back();
        column_dice.push_front(back);
        // update row
        row_dice[top_index] = next_top;
    }
    copy_func();
    // print top dice no
    cout << column_dice[top_index] << '\n';
}

void rolling_row(int dir){
    if(dir == 1){
        int after_y = y + 1;
        if(after_y < 0 || after_y >= m) return;
        else y = after_y; 

        int next_left = column_dice.back();
        int next_top = row_dice.front();
        int next_bottom = row_dice.back();
        // update row
        row_dice.pop_back();
        row_dice.push_front(next_left);
        // update column
        column_dice.pop_back();
        column_dice.push_back(next_bottom);
        column_dice[top_index] = next_top;
    }else if(dir == 2){
        int after_y = y - 1;
        if(after_y < 0 || after_y >= m) return;
        else y = after_y; 

        int next_right = column_dice.back();
        int next_top = row_dice.back();
        int next_bottom = row_dice.front();
        // update row
        row_dice.pop_front();
        row_dice.push_back(next_right);
        // update column
        column_dice.pop_back();
        column_dice.push_back(next_bottom);
        column_dice[top_index] = next_top;
    }
    copy_func();
    // print top dice no
    cout << column_dice[top_index] << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // input vairous parameters
    cin >> n >> m >> x >> y >> k;
    // input map score
    for(int i = 0;i < n;i++){
        vector<int> row_map;
        for(int j = 0;j < m;j++){
            int floor_score;
            cin >> floor_score;
            row_map.push_back(floor_score);
        }
        map.push_back(row_map);
    }
    // input dice dir
    for(int i = 0;i < k;i++){
        int dir; // dir
        cin >> dir;
        // rolling
        if(dir == 1 || dir == 2){
            rolling_row(dir);
        }else if(dir == 3 || dir == 4){
            rolling_column(dir);
        }
    }
}