#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0;
    stack<char> s;
    string ps;
    cin >> ps;
    for(int i = 0;i < ps.length();i++){
        if(ps[i] == '(') s.push('(');
        else{
            if(ps[i-1] == '('){
                s.pop();
                ans += s.size();
            }
            else{
                s.pop();
                ans++;
            }
        }
    }
    cout << ans;
}