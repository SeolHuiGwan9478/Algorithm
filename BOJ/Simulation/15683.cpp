// https://www.acmicpc.net/problem/15683
#include <iostream>
#include <vector>
#define X first;
#define Y second;
using namespace std;

// global variable
int n, m;
int min_cnt; // minimum count
int k = 0; // cctv count
int office[10][10]; // ofiice board
char marking[10][10]; // marking board
vector<pair<int, int>> v;
// fill # into board function
void fill_board(int cur_i, int cur_j, int dir, vector<pair<int, int>> &fill_record){
    // dir : 0, 동
    if(dir == 0){
        // 가장 오른쪽에 cctv 설치할 경우
        if(cur_j == m-1) return;
        // fill #
        for(int j = cur_j+1;j < m;j++){
            if(office[cur_i][j] == 6) return; // 벽일 경우
            if(office[cur_i][j] != 0 || marking[cur_i][j] == '#') continue; // 다른 cctv일 경우 또는 이미 감시되고 있을 경우
            // marking
            marking[cur_i][j] = '#';
            fill_record.push_back({cur_i, j});
        }
    }
    // dir : 1, 서
    else if(dir == 1){
        // 가장 왼쪽 cctv 설치할 경우
        if(cur_j == 0) return;
        // fill #
        for(int j = cur_j-1;j >= 0;j--){
            if(office[cur_i][j] == 6) return; // 벽일 경우
            if(office[cur_i][j] != 0 || marking[cur_i][j] == '#') continue; // 다른 cctv일 경우 또는 이미 감시되고 있을 경우
            // marking
            marking[cur_i][j] = '#';
            fill_record.push_back({cur_i, j});
        }
    }
    // dir : 2, 남
    else if(dir == 2){
        // 가장 아래쪽 cctv 설치할 경우
        if(cur_i == n-1) return;
        // fill #
        for(int i = cur_i+1;i < n;i++){
            if(office[i][cur_j] == 6) return; // 벽일 경우
            if(office[i][cur_j] != 0 || marking[i][cur_j] == '#') continue; // 다른 cctv일 경우 또는 이미 감시되고 있을 경우
            // marking
            marking[i][cur_j] = '#';
            fill_record.push_back({i, cur_j});
        }
    }
    else if(dir == 3){
        // 가장 위쪽 cctv 설치할 경우
        if(cur_i == 0) return;
        // fill #
        for(int i = cur_i-1;i >= 0;i--){
            if(office[i][cur_j] == 6) return; // 벽일 경우
            if(office[i][cur_j] != 0 || marking[i][cur_j] == '#') continue; // 다른 cctv일 경우 또는 이미 감시되고 있을 경우
            // marking
            marking[i][cur_j] = '#';
            fill_record.push_back({i, cur_j});
        }
    }
}

// fill # into board function
void unfill_board(int cur_i, int cur_j, vector<pair<int, int>> &fill_record){
    for(int i = 0;i < fill_record.size();i++){
        pair<int, int> cur = fill_record[i];
        int nx = cur.X;
        int ny = cur.Y;
        marking[nx][ny] = '0';
    }
    fill_record.clear();
}

void func(int cnt){
    if(cnt == k){
        int cur_cnt = 0;
        // counting no suvailance
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(office[i][j] == 0 && marking[i][j] == '0'){
                    cur_cnt += 1;
                }
            }
        }
        if(min_cnt > cur_cnt) min_cnt = cur_cnt;
        return;
    }
    pair<int, int> cur = v[cnt];
    vector<pair<int, int>> fill_record;
    int cur_i = cur.X; // cctv i point
    int cur_j = cur.Y; // cctv j point
    int cctv_no = office[cur_i][cur_j]; // cctv number
    if(cctv_no == 1){ // cctv 1 case
        for(int i = 0;i < 4;i++){
            fill_board(cur_i, cur_j, i, fill_record);
            //cout << "[fill] cnt: " << cnt << " min_cnt: " << min_cnt << "i: " << i << '\n';
            func(cnt+1);
            unfill_board(cur_i, cur_j, fill_record);
            //cout << "[unfill] cnt: " << cnt << " min_cnt: " << min_cnt << " i: " << i << '\n';
        }
    }
    else if(cctv_no == 2){ // cctv 2 case
        for(int i = 0;i < 2;i++){
            if(i == 0){ // 가로 방향
                fill_board(cur_i, cur_j, 0, fill_record);
                fill_board(cur_i, cur_j, 1, fill_record);
                func(cnt+1);
                unfill_board(cur_i, cur_j, fill_record);
                unfill_board(cur_i, cur_j, fill_record);
            }
            else if(i == 1){ // 세로 방향
                fill_board(cur_i, cur_j, 2, fill_record);
                fill_board(cur_i, cur_j, 3, fill_record);
                func(cnt+1);
                unfill_board(cur_i, cur_j, fill_record);
                unfill_board(cur_i, cur_j, fill_record);
            }
        }
    }
    else if(cctv_no == 3){
        for(int i = 0;i < 4;i++){
            if(i == 0){ // 북동
                fill_board(cur_i, cur_j, 0, fill_record);
                fill_board(cur_i, cur_j, 3, fill_record);
                func(cnt+1);
                unfill_board(cur_i, cur_j, fill_record);
                unfill_board(cur_i, cur_j, fill_record);
            }
            else if(i == 1){ // 남동
                fill_board(cur_i, cur_j, 0, fill_record);
                fill_board(cur_i, cur_j, 2, fill_record);
                func(cnt+1);
                unfill_board(cur_i, cur_j, fill_record);
                unfill_board(cur_i, cur_j, fill_record);
            }
            else if(i == 2){ // 남서
                fill_board(cur_i, cur_j, 1, fill_record);
                fill_board(cur_i, cur_j, 2, fill_record);
                func(cnt+1);
                unfill_board(cur_i, cur_j, fill_record);
                unfill_board(cur_i, cur_j, fill_record);
            }
            else if(i == 3){ // 북서
                fill_board(cur_i, cur_j, 1, fill_record);
                fill_board(cur_i, cur_j, 3, fill_record);
                func(cnt+1);
                unfill_board(cur_i, cur_j, fill_record);
                unfill_board(cur_i, cur_j, fill_record);
            }
        }
    }
    else if(cctv_no == 4){
        for(int i = 0;i < 4;i++){
            if(i == 0){ // 북동남
                fill_board(cur_i, cur_j, 0, fill_record);
                fill_board(cur_i, cur_j, 2, fill_record);
                fill_board(cur_i, cur_j, 3, fill_record);
                func(cnt+1);
                unfill_board(cur_i, cur_j, fill_record);
                unfill_board(cur_i, cur_j, fill_record);
                unfill_board(cur_i, cur_j, fill_record);
            }
            else if(i == 1){ // 동남서
                fill_board(cur_i, cur_j, 0, fill_record);
                fill_board(cur_i, cur_j, 1, fill_record);
                fill_board(cur_i, cur_j, 2, fill_record);
                func(cnt+1);
                unfill_board(cur_i, cur_j, fill_record);
                unfill_board(cur_i, cur_j, fill_record);
                unfill_board(cur_i, cur_j, fill_record);
            }
            else if(i == 2){ // 남서북
                fill_board(cur_i, cur_j, 1, fill_record);
                fill_board(cur_i, cur_j, 2, fill_record);
                fill_board(cur_i, cur_j, 3, fill_record);
                func(cnt+1);
                unfill_board(cur_i, cur_j, fill_record);
                unfill_board(cur_i, cur_j, fill_record);
                unfill_board(cur_i, cur_j, fill_record);
            }
            else if(i == 3){ // 서북동
                fill_board(cur_i, cur_j, 0, fill_record);
                fill_board(cur_i, cur_j, 1, fill_record);
                fill_board(cur_i, cur_j, 3, fill_record);
                func(cnt+1);
                unfill_board(cur_i, cur_j, fill_record);
                unfill_board(cur_i, cur_j, fill_record);
                unfill_board(cur_i, cur_j, fill_record);
            }
        }
    }
    else if(cctv_no == 5){
        fill_board(cur_i, cur_j, 0, fill_record);
        fill_board(cur_i, cur_j, 1, fill_record);
        fill_board(cur_i, cur_j, 2, fill_record);
        fill_board(cur_i, cur_j, 3, fill_record);
        func(cnt+1);
        unfill_board(cur_i, cur_j, fill_record);
        unfill_board(cur_i, cur_j, fill_record);
        unfill_board(cur_i, cur_j, fill_record);
        unfill_board(cur_i, cur_j, fill_record);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // input
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> office[i][j];
            if(office[i][j] != 0 && office[i][j] != 6){
                v.push_back({i, j}); // cctv point push
                k += 1;
            }
        }
    }
    min_cnt = n * m;
    fill(&marking[0][0], &marking[9][10], '0');
    func(0);
    cout << min_cnt;
    return 0;
}