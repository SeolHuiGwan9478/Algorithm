#include <iostream>
#include <deque>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, L;
    deque<pair<int, int>> DQ;
    cin >> N >> L;
    for(int i = 1;i <= N;i++){
        int ai;
        //값 입력받기
        cin >> ai;
        //덱의 범위를 넘어가는 값이면 pop한다. -> 범위검증
        if(!DQ.empty() && (i-L == DQ.front().second)) DQ.pop_front();
        //유효하지 않는 값이면 제거해준다. -> 유효검증
        while(!DQ.empty() && DQ.back().first > ai){
            DQ.pop_back();
        }
        //입력받은 값 인덱스와 함께 삽입
        DQ.push_back({ai,i});
        cout << DQ.front().first << " ";
    }
}