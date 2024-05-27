#include <iostream>
using namespace std;

int main(){
    int arr[10] = {3, 2, 7, 116, 62, 235, 1, 23, 55, 77};
    int n = 10;
    for(int i = 1;i < n;i++){
        int key = i;
        int key_value = arr[i];
        for(int j = i-1;j >= 0;j--){
            if(arr[j] > key_value){
                arr[j+1] = arr[j];
                key--;
            }else{
                break;
            }
        }
        arr[key] = key_value;
    }
    // print
    for(int i = 0;i < n;i++){
        cout << arr[i] << ' ';
    }
}