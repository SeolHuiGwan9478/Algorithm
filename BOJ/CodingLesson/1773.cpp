// https://www.acmicpc.net/problem/1773
#include<iostream>
#include<vector>
using namespace std;

int n, c;
vector<int> periods;
int pop_cnt = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;

    for(int i = 0;i < n;i++){
        int period;
        cin >> period;
        periods.push_back(period);
    }

    for(int i = 1;i <= c;i++){
        bool is_pop = false;
        for(int j = 0;j < n;j++){
            int period = periods[j];
            if(i%period == 0){
                is_pop = true;
            }
        }
        if(is_pop){
            pop_cnt += 1;
        }
    }

    cout << pop_cnt;
}