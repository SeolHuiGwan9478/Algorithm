#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int t, n, m;
vector<int> a;
vector<int> b;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for(int i = 0;i < t;i++){
        cin >> n >> m;
        for(int j = 0;j < n;j++){
            int num;
            cin >> num;
            a.push_back(num);
        }
        for(int j = 0;j < m;j++){
            int num;
            cin >> num;
            b.push_back(num);
        }
        sort(a.begin(), a.end(), greater<>());
        sort(b.begin(), b.end());
        int count = 0;
        for(int j = 0;j < a.size();j++){
            for(int k = 0;k < b.size();k++){
                if(a[j] > b[k]){
                    count++;
                }else{
                    break;
                }
            }
            if(count == 0){
                break;
            }
        }
        cout << count << '\n';
        a.clear();
        b.clear();
    }
}