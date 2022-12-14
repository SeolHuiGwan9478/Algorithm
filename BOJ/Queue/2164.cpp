#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    queue<int> Q;
    cin >> n;
    for(int i = 1;i <= n;i++) Q.push(i);
    while(Q.size() != 1){
        //카드 버리기
        Q.pop();
        if(Q.size() == 1) break;
        //카드 옮기기
        int move_card = Q.front();
        Q.pop();
        Q.push(move_card);
        if(Q.size() == 1) break;
    }
    cout << Q.front() << '\n';
}