#include <iostream>
#include <string>
using namespace std;

int winningTime[3], score[3]; //이긴 시간, 득점
int n, curGoalTeam, minute, second, cur; //현재 득점 팀
string goalTime; //현재 득점 시간

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n; // N 입력
    for(int i = 0;i < n;i++){
        cin >> curGoalTeam >> goalTime;

        minute = ((goalTime[0] - '0') * 10 + (goalTime[1] - '0')) * 60;
        second = (goalTime[3] - '0') * 10 + (goalTime[4] - '0');
        cur = minute + second; //입력받은 시간 -> 초로 변경

		if(curGoalTeam == 1){
			if(score[1] == score[2]) winningTime[1] += ((48*60) - cur);
			score[1]++;
			if(score[1] == score[2]) winningTime[2] -= ((48*60) - cur);
		}
		else if(curGoalTeam == 2){
			if(score[1] == score[2]) winningTime[2] += ((48*60) - cur);
			score[2]++;
			if(score[1] == score[2]) winningTime[1] -= ((48*60) - cur);
		}
    }
    printf("%02d:%02d\n", winningTime[1]/60, winningTime[1]%60);
    printf("%02d:%02d\n", winningTime[2]/60, winningTime[2]%60);
}