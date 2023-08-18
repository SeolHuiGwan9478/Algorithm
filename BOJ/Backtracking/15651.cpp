#include <iostream>
#include <vector>
using namespace std;

// glboal variable
int n, m;
vector<int> permutation;
// backtracking recursion func
void func(int cnt){
    if(cnt == m){
        for(int i = 0;i < m;i++){
            cout << permutation[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 1;i <= n;i++){
        permutation.push_back(i);
        func(cnt+1);
        permutation.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(0);
}