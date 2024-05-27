#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int arr[10] = {3, 2, 7, 116, 62, 235, 1, 23, 55, 77};
    int n = 10;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
    // print
    for(int i = 0;i < n;i++){
        cout << arr[i] << ' ';
    }
}