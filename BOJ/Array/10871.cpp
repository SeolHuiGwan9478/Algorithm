#include <iostream>
using namespace std;

int main(void){
    int n, x;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    int* a = new int[n];
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < n;i++){
        if(a[i] < x){
            cout << a[i] << ' ';
        }
    }
    return 0;
}

/*
int main(void){
    int n, x, tmp;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    while(n--){
        cin >> tmp;
        if(tmp < x) cout << t << ' ';
    }
    return 0;
}
*/
