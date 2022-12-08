#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    long long banchmarking_sum = 0;
    vector<int> v;
    stack<pair<int, int>> s;
    cin >> N;
    s.push({1000000001, N+1});
    for(int i = 0;i < N;i++){
        int height;
        cin >> height;
        v.push_back(height);
    }
    for(int i = v.size();i > 0;i--){
        int height = v[i-1];
        while(s.top().first < height){
            s.pop();
        }
        banchmarking_sum += (s.top().second - i - 1);
        s.push({height, i});
    }
    cout << banchmarking_sum;
    return 0;
}