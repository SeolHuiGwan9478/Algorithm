#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n; // home
vector<vector<int>> costs;
int d[1001][3] = {0,}; // dp table

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0;i < n;i++){ // input
        int r,g,b;
        vector<int> cost;
        cin >> r >> g >> b;
        cost.push_back(r);
        cost.push_back(g);
        cost.push_back(b);
        costs.push_back(cost);
    }
    // init value
    d[1][0] = costs[0][0];
    d[1][1] = costs[0][1];
    d[1][2] = costs[0][2];
    // fill dp table
    for(int i = 2;i <= n;i++){
        d[i][0] = min(d[i-1][1], d[i-1][2]) + costs[i-1][0];
        d[i][1] = min(d[i-1][0], d[i-1][2]) + costs[i-1][1];
        d[i][2] = min(d[i-1][0], d[i-1][1]) + costs[i-1][2];
    }
    int min_cost = *min_element(d[n], d[n]+3);
    cout << min_cost;
}