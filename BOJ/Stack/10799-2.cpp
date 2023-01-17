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
            if(ps[i-1] == '('){ //레이저일 경우
                s.pop(); //앞에서 막대라고 착각하고 stack에 s[i]를 넣었으므로 pop
                ans += s.size(); //막대의 개수만큼 ans에 추가
            }
            else{ //막대의 끝일 경우
                s.pop(); //막대의 개수를 1 감소
                ans++; //막대 1개가 절단된 것과 동일한 상황이므로 ans에 1 추가
            }
        }
    }
    cout << ans;
}