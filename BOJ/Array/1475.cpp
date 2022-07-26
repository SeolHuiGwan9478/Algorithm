#include <iostream>
#include <cmath>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int check[10] = {0,};
    string rno; //room number
    int sets = 0, sixnines = 0;
    cin >> rno;
    for(int i = 0;i < rno.length();i++){
        int tmp = rno[i] - '0';
        check[tmp] += 1;
    }
    for(int i = 0;i < 10;i++){
        if(i == 6 || i == 9) sixnines += check[i];
        else{
            if(sets < check[i]) sets = check[i];
        }
    }
    if(sets < ceil(sixnines/2.0)){
        sets = ceil(sixnines/2.0);
    }
    cout << sets;
    return 0;
}