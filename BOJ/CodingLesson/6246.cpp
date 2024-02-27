// https://www.acmicpc.net/problem/6246
#include <iostream>
#include <vector>
using namespace std;

int n, q;
int L, l;
int empty_slot = 0;
vector<bool> balloons;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 0;i < n;i++){
        balloons.push_back(false);
    } // balloon init
    for(int i = 0;i < q;i++){
        cin >> L >> l;
        for(int j = L-1;j < n;j+=l){
            if(balloons[j] == false){
                balloons[j] = true;
            }
        }
    }
    // count empty slot
    for(int i = 0;i < n;i++){
        if(balloons[i] == false){
            empty_slot += 1;
        }
    }

    cout << empty_slot;
}