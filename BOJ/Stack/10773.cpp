#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int K, num, size;
    int sum = 0;
    stack<int> s;
    cin >> K;
    for(int i = 0;i < K;i++){
        cin >> num;
        if(num == 0) s.pop();
        else s.push(num);
    }
    
    size = s.size();
    for(int i = 0;i < size;i++){
        sum += s.top();
        s.pop();
    }
    cout << sum << '\n';
}