#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    int cnt = 0;
    cin >> N;
    for(int i = 0;i < N;i++){
        string word;
        stack<char> s;
        cin >> word;
        for(auto ch : word){
            if(!s.empty()){
                if(ch == s.top()) s.pop();
                else s.push(ch);
            }
            else s.push(ch);
        }
        if(s.empty()) cnt++;
    }
    cout << cnt;
}