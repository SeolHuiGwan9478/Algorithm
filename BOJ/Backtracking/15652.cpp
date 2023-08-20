// https://www.acmicpc.net/problem/15652
#include <iostream>
#include <vector>
using namespace std;

// global variable
int n, m;
vector<int> seq;

void func(int cnt, int start){
    if(cnt == m){
        for(int i = 0;i < m;i++){
            cout << seq[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = start+1;i <= n;i++){
        seq.push_back(i);
        func(cnt+1, i-1);
        seq.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(0,0);
    return 0;
}