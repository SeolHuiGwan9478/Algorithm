#include <iostream>
using namespace std;

int t, w; // drop sec, move cnt
int drop_pos[1005] = {0,};
int d[1005][35][3] = {0,};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t >> w;
    for(int i = 1;i <= t;i++){
        cin >> drop_pos[i];
    } // input value
    for (int i = 1; i <= t; i++) {
        int pos = drop_pos[i];
        d[i][0][1] = d[i-1][0][1] + (pos == 1 ? 1 : 0);
        for (int j = 1; j <= w; j++) { // j번 이동
          if (i < j) break; // 현재 시간보다 많이 이동할 수 없다
          if (pos == 1) { // 1번 나무인 경우
            d[i][j][1] = max(d[i - 1][j - 1][2], d[i - 1][j][1]) + 1;
            d[i][j][2] = max(d[i - 1][j - 1][1], d[i - 1][j][2]);
          }
          else { // 2번 나무인 경우
            d[i][j][1] = max(d[i - 1][j - 1][2], d[i - 1][j][1]);
            d[i][j][2] = max(d[i - 1][j - 1][1], d[i - 1][j][2]) + 1;
          }
    }
  }
    int max_value = 0;
    for(int j = 0;j <= w;j++){
        for(int k = 1;k <= 2;k++){
            if(max_value < d[t][j][k]){
                max_value = d[t][j][k];
            }
        }
    }
    cout << max_value;
}