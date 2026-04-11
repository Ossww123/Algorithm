#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    
    for(int j=0; j<n-1; j++)
    {
        vector<vector<int>> edges(n+1);
        for(int i=0; i<n-1; i++)
        {
            if (i == j) continue;
            edges[wires[i][0]].push_back(wires[i][1]);
            edges[wires[i][1]].push_back(wires[i][0]);
        }
        
        stack<int> stk;
        vector<int> visited(n+1, false);
        
        visited[1] = true;
        stk.push(1);
        int cnt = 1;
        while(!stk.empty())
        {
            int start = stk.top();
            stk.pop();
            
            for (int e : edges[start])
            {
                if (visited[e]) continue;
                visited[e] = true;
                cnt++;
                stk.push(e);
            }
        }
        
        answer = min(answer, abs(cnt - (n - cnt)));
    }
    
    return answer;
}