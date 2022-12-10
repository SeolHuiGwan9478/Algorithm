#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    long long pairs = 0;
    stack<pair<int,int>> S;
    cin >> N;
    //키 입력받기
    for(int i = 0;i < N;i++){
        int height;
        cin >> height;
        int cnt = 1;
        while(!S.empty() && S.top().first <= height){
            if(S.top().first == height) cnt += S.top().second;
            pairs += S.top().second;
            S.pop();
        }
       if(!S.empty()) pairs++;
       S.push({height, cnt});
    }
    cout << pairs;
}