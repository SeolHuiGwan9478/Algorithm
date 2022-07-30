#include <iostream>
using namespace std;

int char_word1[26]; //word1 알파벳 확인 위한 배열
int char_word2[26]; //word2 알파벳 확인 위한 배열
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int min_cnt = 0;
    string word1, word2;
    cin >> word1; //word1 입력
    cin >> word2; //word2 입력
    for(auto c : word1) char_word1[c - 'a'] += 1;
    for(auto c : word2) char_word2[c - 'a'] += 1;
    for(int i = 0;i < 26;i++){
        if(char_word1[i] >= char_word2[i]){
            min_cnt += (char_word1[i] - char_word2[i]);
        }
        else{
            min_cnt += (char_word2[i] - char_word1[i]);
        }
    }
    cout << min_cnt;
}