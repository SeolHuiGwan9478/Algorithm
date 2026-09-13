#include<bits/stdc++.h>

using namespace std;

// global variable init
vector<char> vowel = {'A', 'E', 'I', 'O', 'U'};
string t_word = "";
int cur_count = 0;
int answer = 0;

void find_order(string cur_word){
    // base condition
    int word_len = cur_word.length();
    if(word_len == 5 || answer != 0) return;
    // main logic
    for(int idx = 0;idx < 5;idx++){
        cur_word += vowel[idx];
        cur_count += 1;
        if(cur_word == t_word){
            answer = cur_count;
            break;
        }
        find_order(cur_word);
        cur_word = cur_word.substr(0, word_len);
    }
}

int solution(string word) {
    // init
    ios::sync_with_stdio(0);
    cin.tie(0);
    t_word = word;
    string cur_word = "";
    find_order(cur_word);
    return answer;
}
