#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    stack<int> S; //스택 선언
    vector<int> an, nge;
    cin >> N;
    for(int i = 0;i < N;i++){
        int ai;
        cin >> ai;
        an.push_back(ai);
    }
    //벡터 리버싱
    for(int i = N-1;i >= 0;i--){
        int cur = an[i];
        while(!S.empty() && (S.top() <= cur)) S.pop();
        if(S.empty()) nge.push_back(-1);
        else nge.push_back(S.top());
        S.push(cur);
    }
    //nge 출력
    for(int i = nge.size()-1;i >= 0;i--) cout << nge[i] << " "; 
}