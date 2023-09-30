// https://www.acmicpc.net/problem/15686
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#define X first;
#define Y second;
using namespace std;

int n, m; // city size n, optimization of chicken m
int city[50][50]; // city arr
int min_dist = 10000; // 최대 치킨 거리의 합, 초기값 : 100(최대 거리) * 100(최대 집 개수)
vector<pair<int, int>> chickens;
vector<pair<int, int>> selected_chickens;
vector<pair<int, int>> homes;
vector<int> combination;

int calc_dist(pair<int, int> home, pair<int, int> chicken){
    // local var
    int hx = home.X;
    int hy = home.Y;
    int cx = chicken.X;
    int cy = chicken.Y;
    int gap_x = abs(hx-cx);
    int gap_y = abs(hy-cy);
    int distance = gap_x + gap_y;
    return distance;
}

void func(){
    int sum_dist = 0;
    vector<int> tmp_dist;
    for(int i = 0;i < homes.size();i++){
        pair<int, int> cur_home = homes[i];
        tmp_dist.clear();
        for(int j = 0;j < selected_chickens.size();j++){
            pair<int, int> cur_chicken = selected_chickens[j];
            int cur_dist = calc_dist(cur_home, cur_chicken);
            tmp_dist.push_back(cur_dist);
        }
        int cur_min = *min_element(tmp_dist.begin(), tmp_dist.end());
        sum_dist += cur_min;
    }
    if(min_dist > sum_dist){
        min_dist = sum_dist;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> city[i][j]; // input city
            if(city[i][j] == 1) homes.push_back({i,j});
            else if(city[i][j] == 2) chickens.push_back({i,j});
        }
    }
    // making vector for combination
    for(int i = 0;i < chickens.size();i++){
        if(i < m) combination.push_back(0);
        else combination.push_back(1);
    }
    do{
        selected_chickens.clear(); // intialize selected_chickens vector
        for(int i = 0;i < combination.size();i++){
            if(combination[i] == 0){
                pair<int, int> chicken = chickens[i];
                selected_chickens.push_back(chicken);
            }
        }
        func();
    }while(next_permutation(combination.begin(), combination.end()));
    cout << min_dist;
}