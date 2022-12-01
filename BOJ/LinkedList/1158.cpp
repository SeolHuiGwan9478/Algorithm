#include <iostream>
#include <list>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, n;
    list<int> yosepus;
    cin >> k >> n;

    for(int i = 1;i <= k;i++){
        yosepus.push_back(i);
    }
    auto it = yosepus.begin();
    cout << "<";
    while(yosepus.size() != 0){
        for(int i = 0;i < n-1;i++){
            if(it == yosepus.end()) it = yosepus.begin();
            it++;
            if(it == yosepus.end()) it = yosepus.begin();
        }
        if(yosepus.size() != 1){cout << *it << ", ";}
        else{cout << *it << ">";}
        it = yosepus.erase(it);
    }
}