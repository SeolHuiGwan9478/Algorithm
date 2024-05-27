#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int arr[10] = {3, 2, 7, 116, 62, 235, 1, 23, 55, 77};
    int n = 10;
    for(int i = n-1;i >= 0;i--){
        int max_idx = 0;
        for(int j = 0;j <= i;j++){
            if(arr[max_idx] < arr[j]){
                max_idx = j;
            }
            swap(arr[max_idx], arr[i]);
        }
    }
    // print
    for(int i = 0;i < n;i++){
        cout << arr[i] << ' ';
    }
}