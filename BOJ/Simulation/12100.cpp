// https://www.acmicpc.net/problem/12100
#include <iostream>
#include <vector>
#include <algorithm>
#define X first;
#define Y second;
using namespace std;

int n; // board size n
int max_sum = 0; // max num block
int board[20][20]; // game board
int is_integer[20][20]; // // 한번 합쳐졌는지 확인하는 배열
vector<pair<pair<int,int>, int>> init_v; // init position vector

vector<pair<pair<int,int>, int>> move(int dir, vector<pair<pair<int,int>, int>> pos){
    vector<pair<pair<int,int>, int>> new_v;
    fill(&is_integer[0][0], &is_integer[19][20], 0); // is_integer initialize
    // 1. 이동 후 보드 밖을 나갈 경우(* 수를 만나지 못한 경우)
    // 2. 이동하다 수를 만났는데 같은 수일 경우
    // 3. 이동하다 수를 만났는데 다른 수일 경우
    if(dir == 1 || dir == 3) reverse(pos.begin(), pos.end());
    for(int i = 0;i < pos.size();i++){
        int nx = pos[i].first.first;
        int ny = pos[i].first.second;
        int cur_block = board[nx][ny];
        if(dir == 0){
            int nxt_ny = ny - 1; // 다음 y 좌표 초기화
            while(true){
                if(nxt_ny < 0){
                    board[nx][ny] = 0; // 기존 블럭 0으로 초기화
                    board[nx][nxt_ny+1] = cur_block; // 블럭 이동
                    break;
                }
                int pre_block = board[nx][nxt_ny];
                if(pre_block != 0 && pre_block == cur_block){
                    board[nx][ny] = 0; // 기존 블럭 0으로 초기화
                    if(is_integer[nx][nxt_ny] == 1){
                        board[nx][nxt_ny+1] = cur_block;
                        break;
                    }else{
                        board[nx][nxt_ny] *= 2; // 블럭 합치기
                        is_integer[nx][nxt_ny] = 1; // 병합 기록
                        break;
                    }
                }
                else if(pre_block != 0 && pre_block != cur_block){
                    board[nx][ny] = 0; // 기존 블럭 0으로 초기화
                    board[nx][nxt_ny+1] = cur_block; // 블럭 이동
                    break;
                }
                nxt_ny--; // y좌표 감소
            }
        } // left
        else if(dir == 1){
            int nxt_ny = ny + 1; // 다음 y 좌표 초기화
            while(true){
                if(nxt_ny >= n){
                    board[nx][ny] = 0; // 기존 블럭 0으로 초기화
                    board[nx][nxt_ny-1] = cur_block; // 블럭 이동
                    break;
                }
                int pre_block = board[nx][nxt_ny];
                if(pre_block != 0 && pre_block == cur_block){
                    board[nx][ny] = 0; // 기존 블럭 0으로 초기화
                    if(is_integer[nx][nxt_ny] == 1){
                        board[nx][nxt_ny-1] = cur_block;
                        break;
                    }else{
                        board[nx][nxt_ny] *= 2; // 블럭 합치기
                        is_integer[nx][nxt_ny] = 1;
                        break;
                    }
                }
                else if(pre_block != 0 && pre_block != cur_block){
                    board[nx][ny] = 0; // 기존 블럭 0으로 초기화
                    board[nx][nxt_ny-1] = cur_block; // 블럭 이동
                    break;
                }
                nxt_ny++; // y좌표 증가
            }
        } // right
        else if(dir == 2){
            int nxt_nx = nx - 1; // 다음 x 좌표 초기화
            while(true){
                if(nxt_nx < 0){
                    board[nx][ny] = 0; // 기존 블럭 0으로 초기화
                    board[nxt_nx+1][ny] = cur_block; // 블럭 이동
                    break;
                }
                int pre_block = board[nxt_nx][ny];
                if(pre_block != 0 && pre_block == cur_block){
                    board[nx][ny] = 0; // 기존 블럭 0으로 초기화
                    if(is_integer[nxt_nx][ny] == 1){
                        board[nxt_nx+1][ny] = cur_block;
                        break;
                    }else{
                        board[nxt_nx][ny] *= 2; // 블럭 합치기
                        is_integer[nxt_nx][ny] = 1;
                        break;
                    }
                }
                else if(pre_block != 0 && pre_block != cur_block){
                    board[nx][ny] = 0; // 기존 블럭 0으로 초기화
                    board[nxt_nx+1][ny] = cur_block; // 블럭 이동
                    break;
                }
                nxt_nx--; // x좌표 감소
            }
        } // up
        else if(dir == 3){
            int nxt_nx = nx + 1; // 다음 x 좌표 초기화
            while(true){
                if(nxt_nx >= n){
                    board[nx][ny] = 0; // 기존 블럭 0으로 초기화
                    board[nxt_nx-1][ny] = cur_block; // 블럭 이동
                    break;
                }
                int pre_block = board[nxt_nx][ny];
                if(pre_block != 0 && pre_block == cur_block){
                    board[nx][ny] = 0; // 기존 블럭 0으로 초기화
                    if(is_integer[nxt_nx][ny] == 1){
                        board[nxt_nx-1][ny] = cur_block;
                        break;
                    }else{
                        board[nxt_nx][ny] *= 2; // 블럭 합치기
                        is_integer[nxt_nx][ny] = 1;
                        break;
                    }
                }
                else if(pre_block != 0 && pre_block != cur_block){
                    board[nx][ny] = 0; // 기존 블럭 0으로 초기화
                    board[nxt_nx-1][ny] = cur_block; // 블럭 이동
                    break;
                }
                nxt_nx++; // x좌표 증가
            }
        } // down
    }
    // making new_v
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            int cur_num = board[i][j];
            if(cur_num != 0){
                new_v.push_back({{i,j}, cur_num});
            }
        }
    }
    return new_v;
}

void unmove(vector<pair<pair<int, int>, int>> pre_v){
    fill(&board[0][0], &board[19][20], 0); // board initialize
    for(int i = 0;i < pre_v.size();i++){
        int nx = pre_v[i].first.first;
        int ny = pre_v[i].first.second;
        int num = pre_v[i].second;
        board[nx][ny] = num;
    } // 복구 완료
    return;
}

void func(int cnt, vector<pair<pair<int, int>, int>> pos){
    vector<pair<pair<int, int>, int>> nxt_v;
    if(cnt == 5){
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(max_sum < board[i][j]){
                    max_sum = board[i][j];
                }
            }
        }
        return;
    }
    for(int i = 0;i < 4;i++){
        nxt_v = move(i, pos);
        func(cnt+1, nxt_v);
        unmove(pos);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> board[i][j];
            if(board[i][j] != 0) init_v.push_back({{i, j}, board[i][j]}); // push init position
        }
    } // input board complete
    func(0, init_v);
    cout << max_sum;
}