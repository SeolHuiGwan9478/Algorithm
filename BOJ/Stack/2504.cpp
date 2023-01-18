#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string ps; //문자열 입력
    int cur_score = 0;
    int total_score = 0;
    bool invalid = true;
    vector<char> v;
    cin >> ps;
    for(int i = 0;i < ps.length();i++){
        if(ps[i] == '(' || ps[i] == '['){
            v.push_back(ps[i]);
        }
        else if(ps[i] == ')'){
            if(v.empty() || v.back() != '('){ //유효하지 못한 괄호식
                invalid = false;
                break;
            }
            else if(ps[i-1] == '('){
                v.pop_back();
                cur_score = 2;
                for(auto ch : v){
                    if(ch == '(') cur_score *= 2;
                    else if(ch == '[') cur_score *= 3;
                }
                total_score += cur_score;
            }
            else{
                v.pop_back();
            }
        }
        else if(ps[i] == ']'){
            if(v.empty() || v.back() != '['){ //유효하지 못한 괄호식
                invalid = false;
                break;
            }
            else if(ps[i-1] == '['){
                v.pop_back();
                cur_score = 3;
                for(auto ch : v){
                    if(ch == '(') cur_score *= 2;
                    else if(ch == '[') cur_score *= 3;
                }
                total_score += cur_score;
            }
            else{
                v.pop_back();
            }
        }
    }
    if(!v.empty()) invalid = false;
    if(invalid) cout << total_score;
    else cout << 0;
    return 0;
}