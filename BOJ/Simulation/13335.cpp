// https://www.acmicpc.net/problem/13335
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int n, w, l;
int unit_time = 0;
int idx = 0;
vector<int> trucks;
vector<int> bridge;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // input
    cin >> n >> w >> l;
    for(int i = 0;i < n;i++){
        int truck;
        cin >> truck;
        trucks.push_back(truck);
    }
    // bridge init
    for(int i = 0;i < w;i++){
        bridge.push_back(0);
    }

    // calculate times
    while(true){
        unit_time += 1;
        bridge.erase(bridge.begin()); // erase first element
        if(idx == n){
            // endpoint
            if(accumulate(bridge.begin(), bridge.end(), 0) == 0){
                break;
            }
            continue;
        }
        if(accumulate(bridge.begin(), bridge.end(), 0) + trucks[idx] <= l){
            bridge.push_back(trucks[idx]);
            idx += 1;
        }else{
            bridge.push_back(0);
        }
    }
    cout << unit_time;
}