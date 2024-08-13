#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;

vector<string> serials;

bool compare(const string& a, const string& b){
    int a_len = a.length();
    int b_len = b.length();
    if(a_len < b_len) return true;
    else if(a_len == b_len){
        int a_digit_sum = 0;
        int b_digit_sum = 0;
        for(int i = 0;i < a_len;i++){
            char a_ch = a.at(i);
            char b_ch = b.at(i);
            if(isdigit(a_ch)){
                a_digit_sum += a_ch - '0';
            }
            if(isdigit(b_ch)){
                b_digit_sum += b_ch - '0';
            }
        }
        if(a_digit_sum == b_digit_sum){
            return a < b;
        }
        return a_digit_sum < b_digit_sum;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        string serial;
        cin >> serial;
        serials.push_back(serial);
    } // input
    sort(serials.begin(), serials.end(), compare);
    for(int i = 0;i < n;i++){
        cout << serials.at(i) << '\n';
    }
}