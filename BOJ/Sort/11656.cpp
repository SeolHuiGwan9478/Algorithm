// https://www.acmicpc.net/problem/11656
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string s;
vector<string> postfixes;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    for(int i = 0;i < s.length();i++){
        string postfix = s.substr(i);
        postfixes.push_back(postfix);
    }
    sort(postfixes.begin(), postfixes.end());
    for(int i = 0;i < postfixes.size();i++){
        cout << postfixes[i] << '\n';
    }
}