//BOJ 2805 매개변수 탐색(Parametric Search)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool ispossible(unsigned int mid);
void solve();

int n, m; //나무의 수, 목표 나무의 길이
vector<int> trees;

void solve(){
    //나무의 길이를 정렬
    sort(trees.begin(), trees.end());
    //더 큰 mid를 위해 unsigned int형으로 선언
    unsigned int left = 0, right = trees[trees.size() - 1]; //left는 최소 높이, right 최대 높이
    long long int max_h = 0;
    while(left <= right){
        unsigned int mid = (left + right) / 2;
        unsigned int get_h = 0; //얻은 나무 길이
        for(int i = 0;i < n;i++){
            int gap = trees[i] - mid;
            if(gap <= 0) continue; //만약 절단기 높이 h보다 나무 길이가 작거나 같을 경우 pass
            else get_h += gap; //그렇지 않다면 나무 길이 - 절단기 h 를 통해 얻을 수 있는 나무길이를 더한다.
        }
        if(get_h >= m){
            max_h = mid;
            left = mid + 1; //조건을 만족하면 최대값을 찾기 위해 범위를 증가
        }
        else{
            right = mid - 1;
        }
    }
    cout << max_h;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m; //나무의 수, 목표 나무길이 입력
    trees.assign(n, 0); //벡터 n개만큼 0으로 할당
    for(int i = 0;i < n;i++) cin >> trees[i]; //각 나무의 길이 입력
    solve();
    return 0;
}
