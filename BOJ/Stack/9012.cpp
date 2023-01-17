#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    for(int i = 0;i < t;i++){
        string ps;
        bool invalid = true;
        stack<char> s;
        cin >> ps;
        for(auto ch : ps){
            if(ch == '(') s.push(ch);
            else if(ch == ')'){
                if(s.empty()){
                    invalid = false;
                    break;
                }
                else s.pop();
            }
        }
        if(!s.empty()) invalid = false;
        if(invalid) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}