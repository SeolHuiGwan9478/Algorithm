#include <iostream>
#include<stack>
using namespace std;

int N;
stack<pair<int,int>> tower;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    tower.push({100000001, 0});
    for(int i = 1;i <= N;i++){
        int height;
        cin >> height;
        //어차피 다음 기둥들은 닿을리가 없으므로 pop()
        while(tower.top().first < height){
            tower.pop();
        }
        cout << tower.top().second << " ";
        tower.push({height, i});
    }
}