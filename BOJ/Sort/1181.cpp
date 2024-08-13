// https://www.acmicpc.net/problem/1181
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int n;

bool compare(const string& a, const string& b){
    int a_len = a.length();
    int b_len = b.length();
    if(a_len < b_len){
        return true;
    }else if(a_len == b_len){
        return a < b;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    set<string> no_dup_words;
    cin >> n;
    for(int i = 0;i < n;i++){
        string word;
        cin >> word;
        no_dup_words.insert(word);
    }
    vector<string> words(no_dup_words.begin(), no_dup_words.end());
    sort(words.begin(), words.end(), compare);
    for(int i = 0;i < words.size();i++){
        cout << words[i] << '\n';
    }
}