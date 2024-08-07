#include <iostream>
using namespace std;

int freq[2000001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        int num;
        cin >> num;
        freq[num + 1000000] += 1;
    }
    for(int i = 0;i <= 2000000;i++){
        if(freq[i] != 0){
            for(int j = freq[i];j > 0;j--){
                cout << i-1000000 << '\n';
            }
        }
    }
}