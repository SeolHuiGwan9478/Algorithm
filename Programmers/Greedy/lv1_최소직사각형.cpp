#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    // init
    int final_x = 0;
    int final_y = 0;
    int answer = 0;
    // main logic
    for(vector<int> size : sizes) {
        int cur_x = max(size[0], size[1]);
        int cur_y = min(size[0], size[1]);
        if(final_x < cur_x) final_x = cur_x;
        if(final_y < cur_y) final_y = cur_y;
    }
    answer = final_x * final_y;
    return answer;
}
