#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    queue<int> bfsQ;
    vector<bool> visited(n, false);
    int answer = 0;
    
    for (int cpt = 0; cpt < n ; ++cpt)
    {
        if (visited[cpt])
            continue;
            
        bfsQ.push(cpt);
        ++answer;
        
        while (!bfsQ.empty())
        {
            int start_cpt = bfsQ.front();
            bfsQ.pop();
            
            for(int idx = 0; idx < n; ++idx)
            {
                if(1 == computers[start_cpt][idx]
                   && !visited[idx])
                {
                    visited[idx] = true;
                    bfsQ.push(idx);
                }
            }
        }
    }
    
    
    return answer;
}