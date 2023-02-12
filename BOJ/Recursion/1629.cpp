#include <iostream>
using namespace std;

using ll = long long; // long long 을 ll로 사용하겠다고 선언
ll a, b, c;

ll mulmod(int a, int b, int c){
    if(b == 1) return a % c;
    ll val = mulmod(a, b/2, c);
    val = val * val % c;
    if(b%2 == 0) return val;
    return val * a % c;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c; //입력
    ll result = mulmod(a,b,c);
    cout << result;
}