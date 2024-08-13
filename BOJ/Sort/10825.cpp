// https://www.acmicpc.net/problem/10825
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<tuple<string, int, int, int>> students;

bool compare(const tuple<string, int, int, int>& a, const tuple<string, int, int, int>& b){
    // init
    string a_name = get<0>(a);
    int ak_score = get<1>(a);
    int ae_score = get<2>(a);
    int am_score = get<3>(a);
    string b_name = get<0>(b);
    int bk_score = get<1>(b);
    int be_score = get<2>(b);
    int bm_score = get<3>(b);
    // cmp logic
    if(ak_score > bk_score){
        return true;
    }else if(ak_score == bk_score){
        if(ae_score < be_score){
            return true;
        }else if(ae_score == be_score){
            if(am_score > bm_score){
                return true;
            }else if(am_score == bm_score){
                return a_name < b_name;
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0;i < n;i++){
        tuple<string, int, int, int> student;
        string name;
        int k_score, e_score, m_score;
        cin >> name >> k_score >> e_score >> m_score;
        student = make_tuple(name, k_score, e_score, m_score);
        students.push_back(student);
    }
    sort(students.begin(), students.end(), compare);;
    for(int i = 0;i < students.size();i++){
        tuple<string, int, int, int> student = students[i];
        cout << get<0>(student) << '\n';
    }
}