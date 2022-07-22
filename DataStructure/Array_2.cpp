#include <iostream>
using namespace std;

int check[100];
int func2(int arr[], int len);

int main(void){
    int arr[4] = {4,13,63,87};
    int tmp = func2(arr, 4);
    cout << tmp << '\n';
    return 0;
}

int func2(int arr[], int len){
    int diff;
    for(int i = 0;i < len;i++){
        diff = 100 - arr[i];
        if(check[diff] == 1) return 1;
        check[arr[i]] = 1;
    }
    return 0;
}