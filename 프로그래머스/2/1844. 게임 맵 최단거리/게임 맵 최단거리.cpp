#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int DY[4] = {0, 0, 1, -1};
int DX[4] = {1, -1, 0, 0};

int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    queue<pair<int, int>> bfsQ;
    vector<vector<int>> dist(n, vector<int>(m, -1));
    dist[0][0] = 1;
    bfsQ.push({0, 0});
    
    while(!bfsQ.empty())
    {
        auto [sy, sx] = bfsQ.front();
        bfsQ.pop();
        
        for(int d=0; d<4; d++)
        {
            int ny = sy + DY[d];
            int nx = sx + DX[d];
            
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(dist[ny][nx] != -1) continue;
            if (maps[ny][nx] == 0) continue;
            
            dist[ny][nx] = dist[sy][sx] + 1;
            bfsQ.push({ny, nx});
        }
    }
    
    return dist[n-1][m-1];
}