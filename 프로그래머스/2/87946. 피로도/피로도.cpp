#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int maxValue = 0;

void dfs (vector<bool>& visited, vector<vector<int>>& dungeons, int curr, int n, int count, int remained)
{
    if (curr >= n)
    {
        maxValue = max(maxValue, count);
        return;
    }
    
    for (int i=0;i<n;i++)
    {
        if (visited[i]) continue;
        
        visited[i] = true;
        if (remained >= dungeons[i][0] )
            dfs (visited, dungeons, curr + 1, n, count + 1, remained - dungeons[i][1]);
        dfs (visited, dungeons, curr + 1, n, count, remained);
        visited[i] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons) 
{
    int n = dungeons.size();
    
    vector<bool> visited(n, false);
    
    dfs(visited, dungeons, 0, n, 0, k);
    
    return maxValue;
}