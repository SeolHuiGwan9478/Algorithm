#include <iostream>
#include <vector>
using namespace std;

int dist_1, dist_2, dist_3;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, x, y;
    cin >> a >> b >> x >> y;

    // dist init
    dist_1 = abs(a-b);
    dist_2 = abs(a-x) + abs(y-b);
    dist_3 = abs(a-y) + abs(x-b);

    cout << min(dist_1, min(dist_2, dist_3));
}