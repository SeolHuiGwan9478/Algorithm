#include <iostream>
#include <deque>
#include <sstream>
#include <algorithm>
using namespace std;

void parse(deque<int>& d, string s, int n){
    string snums = s.substr(1, s.length()-2);
    string snum;
    int inum;
    stringstream ss1(snums);
    while(getline(ss1, snum, ',')){
        stringstream ss2(snum);
        ss2 >> inum;
        d.push_back(inum);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for(int i = 0;i < t;i++){
        string p, array;
        int n;
        bool iserror = false;
        bool isrev = false;
        deque<int> dq;
        cin >> p >> n >> array;
        parse(dq, array, n);
        for(char ch : p){
            if(ch == 'R'){
                if(isrev == false) isrev = true;
                else isrev = false;
            }
            else if(ch == 'D'){
                if(dq.empty()){
                    iserror = true;
                    break;
                }
                if(!isrev) dq.pop_front();
                else dq.pop_back();
            }
        }
        if(iserror) cout << "error\n";
        else{
            if(isrev) reverse(dq.begin(), dq.end()); 
            int size = dq.size();
            cout << "[";
            for(int j = 0;j < size;j++){
                cout << dq[j];
                if(j != (size-1)) cout << ",";
            }
            cout << "]\n";
        }
    }
}