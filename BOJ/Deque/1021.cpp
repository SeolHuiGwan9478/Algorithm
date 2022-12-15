#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    int res = 0;
    deque<int> dq;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) dq.push_back(i);
    for(int i = 0;i < m;i++){
        int pos;
        cin >> pos;
        int idx = find(dq.begin(), dq.end(), pos) - dq.begin();
        while(dq.front() != pos){
            //left rotation
            if(idx <= (dq.size() - idx)){
                int front = dq.front();
                dq.pop_front();
                dq.push_back(front);
            }
            else{
                int back = dq.back();
                dq.pop_back();
                dq.push_front(back);
            }
            res++;
        }
        dq.pop_front();
    }
    cout << res;
}