#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph(101);

int difference = 100;

void find_diff(vector<int> cut_wire, int n){
    // init
    vector<vector<int>> copy_graph = graph; // copy graph
    vector<int> is_visited(n+1); // 방문 기록용
    vector<int> node_cnts; // node count 벡터
    queue<int> Q;
    for(int node = 1;node <= n;node++){
        if(is_visited[node] == 1) continue; // case1: 이미 방문
        Q.push(node); // Q push
        is_visited[node] = 1; // 방문 기록
        int cur_count = 1;
        // main logic
        while(!Q.empty()) {
            int cur_node = Q.front(); // 3
            Q.pop();
            vector<int> cur_ad_node = copy_graph[cur_node]; // 4
            int cur_ad_node_size = cur_ad_node.size(); // 1
            for(int i = 0;i < cur_ad_node_size;i++){
                int new_node = cur_ad_node[i];
                if(cut_wire[0] == cur_node && cut_wire[1] == new_node) continue;
                if(cut_wire[0] == new_node && cut_wire[1] == cur_node) continue;
                if(is_visited[new_node] == 1) continue;
                Q.push(new_node); // Q push
                is_visited[new_node] = 1; // mark visit
                cur_count += 1;
            }
        }
        node_cnts.push_back(cur_count);
    }
    difference = min(difference, abs(node_cnts[0] - node_cnts[1]));
}

int solution(int n, vector<vector<int>> wires) {
    // init
    int answer = -1;
    // fill graph
    for(vector<int> wire : wires) {
        int s = wire[0];
        int e = wire[1];
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    // main logic
    for(int idx = 0;idx < wires.size();idx++) {
        vector<int> cut_wire = wires[idx]; // cutting wire
        find_diff(cut_wire, n);
    }
    answer = difference;
    return answer;
}
