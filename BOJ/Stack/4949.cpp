#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str; //문자열 받을 변수
    
    while(true){
        stack<char> S; //스택 선언
        bool invalid = true;
        getline(cin, str);
        if(str == ".") break;
        for(auto ch : str){
            if(ch == '(' || ch == '[') S.push(ch);
            else if(ch == ')'){
                if(!S.empty() && S.top() == '(') S.pop();
                else{
                    invalid = false;
                    break;
                }
            }
            else if(ch == ']'){
                if(!S.empty() && S.top() == '[') S.pop();
                else{
                    invalid = false;
                    break;
                }
            }
        }
        if(!S.empty()) invalid = false;
        if(invalid) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}