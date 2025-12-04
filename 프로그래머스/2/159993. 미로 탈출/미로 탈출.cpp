#include <bits/stdc++.h>

using namespace std;

int DY[4] = {0, 0, 1, -1};
int DX[4] = {1, -1, 0, 0};

int CalDistance(vector<string>& maps, int sY, int sX, int eY, int eX)
{
    if (sX == eX && sY == eY) return 0;
    
    int n = maps.size();
    int m = maps[0].size();
    
    queue<pair<int, int>> bfsQ;
    bfsQ.push({sY, sX});
    vector<vector<int>> visited(n, vector<int>(m, -1));
    visited[sY][sX] = 0;
    
    while (!bfsQ.empty())
    {
        auto [cY, cX] = bfsQ.front();
        bfsQ.pop();
        
        for (int dir = 0; dir < 4; dir++)
        {
            int nY = cY + DY[dir];
            int nX = cX + DX[dir];
            
            if (nY < 0 || nY >= n || nX < 0 || nX >= m) continue;
            if (maps[nY][nX] == 'X') continue;
            if (visited[nY][nX] != -1) continue;
            
            visited[nY][nX] = visited[cY][cX] + 1;
            if (nY == eY && nX == eX) return visited[nY][nX];
            bfsQ.push({nY, nX});
        }
    }
    
    return visited[eY][eX];
}

int solution(vector<string> maps)
{
    int n = maps.size();
    int m = maps[0].size();
    
    int sY = -1, sX = -1, lY = -1, lX = -1, eY = -1, eX = -1;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c = maps[i][j];
            if (c == 'S')
            {
                sY = i; sX = j;
            }
            else if (c == 'L')
            {
                lY = i; lX = j;
            }
            else if (c == 'E')
            {
                eY = i; eX = j;
            }
        }
    }
    
    int from_s_to_l = CalDistance(maps, sY, sX, lY, lX);
    int from_l_to_e = CalDistance(maps, lY, lX, eY, eX);
    
    if (from_s_to_l == -1 || from_l_to_e == -1) return -1;
    
    return from_s_to_l + from_l_to_e;
}
