#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    int gender, grade;
    int rooms = 0;
    int* boy = new int[7]();
    int* girl = new int[7]();
    int* students[2] = {girl, boy};
    cin >> n >> k;
    for(int i = 0;i < n;i++){
        cin >> gender >> grade;
        students[gender][grade] += 1; 
    }
    for(int i = 1;i <= 6;i++){
        rooms += boy[i]/k;
        rooms += girl[i]/k;
        if(boy[i]%k) rooms += 1;
        if(girl[i]%k) rooms += 1;
    }
    cout << rooms;
}