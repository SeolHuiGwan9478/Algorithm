#include <iostream>
using namespace std;

int main(void){
    string command;
    int freq[26] = {0,};
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> command;
    for(auto c : command){
        freq[c-'a'] += 1;
    }
    for(int i = 0; i <26; i++){
        cout << freq[i] << ' ';
    }
    return 0;
}