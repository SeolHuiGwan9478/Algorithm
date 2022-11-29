#include <iostream>
#include <list>
using namespace std;

string commands[500000];
list<char> str;
list<char>::iterator it;

void Lcmd(){
    if(it != str.begin()) it--;
}

void Dcmd(){
    if(it != str.end()) it++;
}

void Bcmd(){
    if(it != str.begin()){
        it--;
        it = str.erase(it);
    }
}

void Pcmd(char ch){
    str.insert(it, ch);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    int m = 0;
    //문자열 입력받기
    cin >> input >> m;
    cin.ignore();
    for(int i = 0;i < m;i++){
        getline(cin, commands[i]);
    }
    //연결 리스트로 변환
    for(int i = 0;i < input.length();i++){
        str.push_back(input[i]);
    }
    it = str.end();
    for(int i = 0;i < m;i++){
        string command = commands[i];
        if(command[0] == 'L'){
            Lcmd();
        }
        else if(command[0] == 'D'){
            Dcmd();
        }
        else if(command[0] == 'B'){
            Bcmd();
        }
        else if(command[0] == 'P'){
            Pcmd(command[2]);
        }
    }
    for(list<char>::iterator tmp = str.begin();tmp != str.end();tmp++){
        cout << *tmp;
    }
    return 0;
}