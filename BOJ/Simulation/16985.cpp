// https://www.acmicpc.net/problem/16985
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

vector<vector<vector<int>>> boards;
vector<vector<vector<int>>> rotated_boards;
vector<vector<vector<int>>> dist_boards(5);
vector<vector<vector<int>>> visited(5);
vector<int> permutation(5);
vector<vector<int>> permutations;
vector<vector<int>> orders;

int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};
queue<tuple<int, int, int>> q;

int anglex[4] = {0,0,4,4};
int angley[4] = {0,4,0,4};
int min_dist = 4000;

void repeated_permutation(int depth){
    if(depth == 5){
        // 벡터 반환
        vector<int> copy_permutation(permutation);
        permutations.push_back(copy_permutation);
        return;
    }
    for(int i = 0;i < 4;i++){
        permutation[depth] = i;
        repeated_permutation(depth+1);
    }
}

void get_order(){
    vector<int> board_no = {0,1,2,3,4};
    do{
        vector<int> order;
        for(int o = 0;o < 5;o++){
            order.push_back(board_no[o]);
        }
        orders.push_back(order);
    }while(next_permutation(board_no.begin(), board_no.end()));
}

void rotate_board(int board_no, int angle){
    // angle : 0=0, 1=90, 2=180, 3=270
    vector<vector<int>> cur_board = boards[board_no];
    vector<vector<int>> rotate_board(cur_board);
    for(int a = 0;a < angle;a++){
        for(int i = 0;i < 5;i++){
            for(int j = 0;j < 5;j++){
                rotate_board[i][j] = cur_board[5-j-1][i];
            }
        }
        cur_board.assign(rotate_board.begin(), rotate_board.end());
    }
    rotated_boards.push_back(rotate_board);
}

void bfs(int sx, int sy, int sz){
    // init q
    q.push(make_tuple(sx, sy, sz));
    visited[sz][sx][sy] = 1;
    dist_boards[sz][sx][sy] = 0;
    while(!q.empty()){
        // pop in queue
        tuple<int, int, int> cur = q.front();
        int cur_x = get<0>(cur);
        int cur_y = get<1>(cur);
        int cur_z = get<2>(cur);
        int cur_dist = dist_boards[cur_z][cur_x][cur_y];
        q.pop();
        for(int i = 0;i < 6;i++){
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];
            int nz = cur_z + dz[i];
            if(nx < 0 || ny < 0 || nz < 0 || nx >= 5 || ny >= 5 || nz >= 5) continue;
            if(rotated_boards[nz][nx][ny] == 0 || visited[nz][nx][ny] == 1) continue;
            
            q.push(make_tuple(nx, ny, nz));
            visited[nz][nx][ny] = 1; // marking
            dist_boards[nz][nx][ny] = cur_dist + 1;
        }
    }
}

void get_final_dist(int sx, int sy, int sz){
    // 000, 040, 400, 440
    // 004, 044, 404, 444
    int cur_x = 4;
    int cur_y = 4;
    int cur_z = 4;
    if(dist_boards[cur_z][cur_x][cur_y] == 0){
        return;
    }
    if(min_dist > dist_boards[cur_z][cur_x][cur_y]){
        min_dist = dist_boards[cur_z][cur_x][cur_y];
    }
}

void print_vector(vector<vector<vector<int>>> v){
    for(int i = 0;i < 5;i++){
        for(int j = 0;j < 5;j++){
            for(int k = 0;k < 5;k++){
                cout << v[i][j][k] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // input boards
    for(int i = 0;i < 5;i++){
        vector<vector<int>> board;
        for(int j = 0;j < 5;j++){
            vector<int> row;
            for(int k = 0;k < 5;k++){
                int space;
                cin >> space; // input row
                row.push_back(space); // push back row
            }
            board.push_back(row);
        }
        boards.push_back(board);
    }
    // 중복 순열 구하기 완료
    repeated_permutation(0);
    get_order();
    for(int i = 0;i < permutations.size();i++){
        vector<int> cur_perm = permutations[i];
        for(int o = 0;o < orders.size();o++){
            vector<int> cur_order = orders[o];
            rotated_boards.clear();
            for(int j = 0;j < cur_perm.size();j++){
                rotate_board(cur_order[j], cur_perm[j]);
            }
            // top start
            int cur_x = 0;
            int cur_y = 0;
            int cur_z = 0;
            // init matrix
            vector<int> empty_v(5,0);
            fill(visited.begin(), visited.end(), vector<vector<int>>(5, empty_v));
            fill(dist_boards.begin(), dist_boards.end(), vector<vector<int>>(5,empty_v));
            if(rotated_boards[cur_z][cur_x][cur_y] == 0) continue;
            bfs(cur_x, cur_y, cur_z);
            //print_vector(dist_boards);
            // min
            get_final_dist(cur_x, cur_y, cur_z);
        }
    }
    if(min_dist == 4000) min_dist = -1;
    cout << min_dist;
}