#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string ps;
    stack<int> s;
    vector<int> lasers;
    int total = 0;
    cin >> ps;
    for(int i = 0;i < ps.length();i++){
        if(ps[i] == '(') s.push(i);
        else if(ps[i] == ')'){
            if(s.empty()) break; //스택이 비어있을 때
            else{ //스택이 차 있을 때
                int gap = i - s.top();
                if(gap == 1) lasers.push_back(i);
                else{
                    int cnt = 0;
                    for(int j = lasers.size()-1;j >= 0;j--){
                        if(s.top() < lasers[j]) cnt++;
                        else break;
                    }
                    cnt++;
                    total += cnt;
                }
                s.pop();
            }
        }
    }
    cout << total;
}