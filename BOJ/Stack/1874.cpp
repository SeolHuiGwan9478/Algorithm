#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int insert = 1;
    bool isfind;
    stack<int> s;
    vector<int> nums;
    vector<char> operators;

    cin >> n;
    for(int i = 0;i < n;i++){
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }
    //찾아야 할 수 차례대로 탐색
    for(int i = 0;i <n;i++){
        int target = nums[i];
        isfind = false;
        while(isfind != true){
            //기존 스택 Top 값 확인
            if(!s.empty() && s.top() == target){
                s.pop();
                operators.push_back('-');
                isfind = true;
            }
            //스택에 추가할 값이 의미가 있는지 파악
            //새로 추가하려는 값이 target 값보다 작을 경우 insert
            //새로 추가하려는 값이 target 값보다 큰 경우 불가능한 수열 -> No 출력
            else if(insert <= target){
                s.push(insert);
                operators.push_back('+');
                insert++;
            }
            else{
                break;
            }
        }
        if(!isfind){
            cout << "NO\n";
            return 0;
        }
    }
    for(int i = 0;i < operators.size();i++) cout << operators[i] << '\n';
    return 0;