#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int x; // input X(integer)
int d[1000001] = {0,};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> x;
    d[1] = 0; // init value
    for(int k = 2;k <= x;k++){
        vector<int> results;
        // init variable
        int divide_three = k/3;
        int divide_two = k/2;
        int minus_one = k-1;
        // divide 3
        if(divide_three != 0 && k % 3 == 0){
            results.push_back(d[divide_three] + 1);
        }
        if(divide_two != 0 && k % 2 == 0){
            results.push_back(d[divide_two] + 1);
        }
        if(minus_one != 0){
            results.push_back(d[minus_one] + 1);
        }
        int min_value = *min_element(results.begin(), results.end());
        d[k] = min_value;
    }
    cout << d[x];
}