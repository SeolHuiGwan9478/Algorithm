#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string* origin = new string[n];
    string* rand = new string[n];
    for(int i = 0;i < n;i++){ 
        cin >> origin[i] >> rand[i];
        sort(origin[i].begin(), origin[i].end());
        sort(rand[i].begin(), rand[i].end()); //정렬
        if(origin[i] == rand[i]) cout << "Possible\n";
        else cout << "Impossible\n";
    }
    return 0;
}