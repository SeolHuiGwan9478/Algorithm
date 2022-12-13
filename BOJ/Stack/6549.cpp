#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(true){
        int n; //기둥 개수 n
        long long max_area = 0;  //최대 직사각형 넓이 max_area
        stack<pair<int, int>> S;
        cin >> n;
        if(n == 0) break;
        for(int i = 0;i < n;i++){
            int h;
            cin >> h;
            int idx = i;
            while(!S.empty() && S.top().first >= h){
                long long area;
                long long width, height;
                height = S.top().first;
                width = i - S.top().second;
                area = width * height;
                max_area = max(max_area, area);
                idx = S.top().second;
                S.pop();
            }
            S.push({h, idx});
        }
        //스택에 남은 것들 처리
        while(!S.empty()){
            long long area;
            long long width, height;
            int i = n;
            height = S.top().first;
            width = i - S.top().second;
            area = width * height;
            max_area = max(max_area, area);
            S.pop();
        }
        cout << max_area << '\n';
    }
    return 0;
}