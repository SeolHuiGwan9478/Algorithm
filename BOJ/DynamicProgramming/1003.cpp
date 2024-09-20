// https://www.acmicpc.net/problem/1003
#include <iostream>
using namespace std;

int t; // input test case
pair<int, int> c_table[41];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // init values
    c_table[0] = {1,0};
    c_table[1] = {0,1};

    cin >> t;
    for(int i = 0;i < t;i++){
        int num;
        cin >> num;
        // fill in dp_table
        for(int j = 2;j <= num;j++){
            c_table[j] = {c_table[j-1].first + c_table[j-2].first, c_table[j-1].second + c_table[j-2].second}; 
        }
        cout << c_table[num].first << ' ' << c_table[num].second << '\n';
    } // input nums
}