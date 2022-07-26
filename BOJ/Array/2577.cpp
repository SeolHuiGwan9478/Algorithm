#include <iostream>
using namespace std;

int main(void){
    int check[10] = {0,};
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b,c;
    string mul;
    cin >> a >> b >> c; //숫자 입력
    mul = to_string(a * b * c);
    for(int i = 0;i < mul.length();i++){
        int tmp = mul[i] - '0';
        check[tmp] += 1;
    }
    for(int i = 0;i < 10;i++) cout << check[i] << '\n';
    return 0;
}