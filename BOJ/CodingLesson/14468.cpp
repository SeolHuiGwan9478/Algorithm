// https://www.acmicpc.net/problem/14468
#include <iostream>
using namespace std;

int pos1[26] = {0,}; // start point
int pos2[26] = {0,}; // end point
int cnt = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string cows;
    cin >> cows;
    // record each cow of position
    for(int i = 0;i < 52;i++){
        char cow = cows[i];
        int idx = cow - 'A';
        if(pos1[idx] == 0){
            pos1[idx] = i+1;
        }else{
            pos2[idx] = i+1;
        }
    }

    for(int i = 0;i < 26;i++){
        for(int j = 0;j < 26;j++){
            if(pos1[i] < pos1[j] && pos1[j] < pos2[i] && pos2[i] < pos2[j]){
                cnt++;
            }
        }
    }

    cout << cnt;
}