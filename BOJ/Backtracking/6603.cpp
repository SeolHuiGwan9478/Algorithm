#include <iostream>
#include <algorithm>
using namespace std;

// global vairable
int k;
int s[20] = {0,};
int combination[20] = {0,};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        cin >> k;
        if(k == 0) break;
        for(int i = 0;i < k;i++){
            cin >> s[i];
        }
        fill(combination+6, combination+k, 1);
        do{
            for(int i = 0;i < k;i++){
                if(combination[i] == 0){
                    cout << s[i] << ' ';
                }
            }
            cout << '\n';
        }while(next_permutation(combination, combination+k));
        cout << '\n';
    }
    return 0;
}