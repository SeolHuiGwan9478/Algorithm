#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

ll n, r, c; //n, r, c 입력

ll zfunc(ll n, ll sr, ll sc, ll vis){
    if(n == 1) return vis;
    ll standard = n/2;
    if(r < sr+standard && c < sc+standard) return zfunc(standard, sr, sc, vis);
    else if(r < sr+standard && c >= sc+standard) return zfunc(standard, sr, sc+standard, vis+standard*standard);
    else if(r >= sr+standard && c < sc+standard) return zfunc(standard, sr+standard, sc, vis+standard*standard*2);
    else return zfunc(standard, sr+standard, sc+standard, vis+standard*standard*3);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> r >> c;
    cout << zfunc(pow(2, n), 0, 0, 0);
}