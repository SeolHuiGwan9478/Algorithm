#include <iostream>
#include <vector>
using namespace std;

int n; //영상의 크기
int video[70][70] = {0,}; //비디오 배열
vector<char> result; //압축결과 저장 벡터

bool check(int m, int x, int y){
    for(int i = x;i < x+m;i++){
        for(int j = y;j < y+m;j++){
            if(video[x][y] != video[i][j]) return false;
        }
    }
    return true;
} //압축 여부 확인 함수

void compress(int m, int x, int y){
    if(check(m,x,y)){
        result.push_back(video[x][y] + '0'); //압축 숫자 대입
        return;
    }
    int half = m/2;
    result.push_back('(');
    for(int i = 0;i < 2;i++){
        for(int j = 0;j < 2;j++) compress(half, x+i*half, y+j*half);
    }
    result.push_back(')');
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n; //n 입력
    for(int i = 0;i < n;i++){
        string line;
        cin >> line; //줄 입력
        for(int j = 0;j < n;j++) video[i][j] = line[j] - '0'; //흑백 영상 입력완료
    }
    compress(n, 0, 0);
    for(auto ch : result) cout << ch;
}