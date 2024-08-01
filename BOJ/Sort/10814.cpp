// https://www.acmicpc.net/problem/10814
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
pair<int, string> judges[100001];
pair<int, string> tmp[100001];

void merge(int st, int en){
    int mid = (st+en)/2;
    int lidx = st;
    int ridx = mid;
    for(int i = st;i < en;i++){
        if(lidx == mid) tmp[i] = judges[ridx++];
        else if(ridx == en) tmp[i] = judges[lidx++];
        else if(judges[lidx].first <= judges[ridx].first){
            tmp[i] = judges[lidx++];
        }else{
            tmp[i] = judges[ridx++];
        }
    }
    for(int i = st;i < en;i++){
        judges[i] = tmp[i];
    }
}

void merge_sort(int st, int en){
    int mid = (st+en)/2;
    if(en-st == 1){
        return;
    }
    merge_sort(st, mid);
    merge_sort(mid, en);
    merge(st, en);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0;i < n;i++){ // input
        pair<int, string> judge;
        cin >> judge.first >> judge.second;
        judges[i] = judge;
    }
    merge_sort(0, n);
    for(int i = 0;i < n;i++){ // output
        pair<int, string> judge = judges[i];
        cout << judge.first << ' ' << judge.second << '\n';
    }
}