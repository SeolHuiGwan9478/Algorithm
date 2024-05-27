#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> A;
vector<int> B;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        int value;
        cin >> value;
        A.push_back(value);
    }
    for(int i = 0;i < m;i++){
        int value;
        cin >> value;
        B.push_back(value);
    }
    A.insert(A.end(), B.begin(), B.end());
    sort(A.begin(), A.end());
    for(int i = 0;i < A.size();i++){
        cout << A[i] << ' ';
    }
}