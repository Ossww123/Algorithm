#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> dist(n+1, -1);
    dist[destination] = 0;
    
    vector<vector<int>> edges(n+1);
    for(vector<int> road : roads){
        int a = road[0];
        int b = road[1];
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    queue<pair<int, int>> bfsQ;
    bfsQ.push({destination, 0});
    
    while(!bfsQ.empty()){
        auto[curr_node, curr_dist] = bfsQ.front();
        bfsQ.pop();
        
        for(int next_node : edges[curr_node]){
            if (dist[next_node] != -1) continue;
            
            dist[next_node] = curr_dist + 1;
            bfsQ.push({next_node, curr_dist + 1});
        }
    }
    
    int num_army = sources.size();
    vector<int> answer(num_army);
    
    for (int i=0;i<num_army;i++){
        answer[i] = dist[sources[i]];
    }
    
    return answer;
}