#include <iostream>
using namespace std;

// global variable
int n, m;
int isused[9] = {0,}; // marking
// backtracking recursion func
void func(int cnt, int start){
    // base condition
    if(cnt == m){
        for(int i = 1;i <= n;i++){
            if(isused[i] == 1) cout << i << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = start+1;i <= n;i++){
        if(isused[i] != 1){
            isused[i] = 1;
            func(cnt+1, i);
            isused[i] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(0, 0);
}