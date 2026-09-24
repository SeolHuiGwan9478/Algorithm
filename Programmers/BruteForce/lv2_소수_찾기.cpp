#include<bits/stdc++.h>

using namespace std;

int final_count = 0; // 최종 개수를 담을 변수

int solution(string numbers) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // init
    int answer = 0;
    vector<char> vc_numbers(numbers.begin(), numbers.end());
    sort(vc_numbers.begin(), vc_numbers.end());
    vector<int> a_numbers; // 조합 가능한 숫자 모음 벡터
    // 순열 구하기
    int max_num_len = vc_numbers.size(); // 최대 길이
    for(int cur_len = 1;cur_len <= max_num_len;cur_len++){
        do{
            string cur_num = "";
            for(int i = 0;i < cur_len;i++) {
                char vc_number = vc_numbers[i];
                cur_num += vc_number;
            }
            int s_cur_num = stoi(cur_num);
            if(s_cur_num == 0 || s_cur_num == 1) continue;
            if(find( // 존재하지 않는 값이면 추가 -> 02, 2와 동일하기 때문임.
                a_numbers.begin(), 
                a_numbers.end(), 
                stoi(cur_num)
            ) == a_numbers.end()){
                a_numbers.push_back(stoi(cur_num));
            }
            reverse(vc_numbers.begin() + cur_len, vc_numbers.end());
        }while(next_permutation(vc_numbers.begin(), vc_numbers.end()));
    }

    // 소수 판별
    final_count = a_numbers.size();
    for(int i = 0;i < a_numbers.size();i++){
        int a_number = a_numbers[i];
        int sqrt_a_number = sqrt(a_number);
        for(int j = 2;j <= sqrt_a_number;j++){
            if(a_number % j == 0){
                final_count -= 1;
                break;
            }
        }
    }
    // for(auto a_number : a_numbers) cout << a_number << '\n';
    answer = final_count;
    return answer;
}
