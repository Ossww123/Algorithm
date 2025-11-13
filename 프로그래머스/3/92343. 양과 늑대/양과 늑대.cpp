#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;


int solution(vector<int> info, vector<vector<int>> edges) {
    int n = info.size();
    vector<vector<int>> graph(n);
    
    for (auto &e : edges) {
        int p = e[0];
        int c = e[1];
        graph[p].push_back(c);
    }
    
    stack<int> stk;
    stk.push(1<<0);
    
    bool visited[1<<17] = {};
    int answer = 0;
    
    while(!stk.empty()){
        int mask = stk.top();
        stk.pop();
        
        if (visited[mask]) continue;
        visited[mask] = true;
        
        int sheep = 0, wolf = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                if (info[i] == 0) sheep++;
                else wolf++;
            }
        }
        
        if (wolf >= sheep) continue;
        
        answer = max(answer, sheep);
        
        for (int i = 0; i < n; ++i) {
            if (!(mask & (1 << i))) continue; // 미방문

            for (int child : graph[i]) {
                if (mask & (1 << child)) continue; // 갔던곳

                int nextMask = mask | (1 << child);
                stk.push(nextMask);
            }
        }
    }
    
    return answer;
}
