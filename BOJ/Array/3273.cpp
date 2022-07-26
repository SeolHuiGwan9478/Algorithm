#include <iostream>
using namespace std;

bool a[2000001];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x, other;
    int pairs = 0;
    cin >> n;
    int* numbers = new int[n];
    for(int i = 0;i < n;i++)cin >> numbers[i];
    cin >> x;
    for(int i = 0;i < n;i++){
        other = x - numbers[i];
        if(other > 0 && a[other]) pairs++;
        a[numbers[i]] = true;
    }
    cout << pairs;
    return 0;
}