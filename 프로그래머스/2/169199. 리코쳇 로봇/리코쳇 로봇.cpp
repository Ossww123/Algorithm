#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int DY[4] = {0, 0, 1, -1};
int DX[4] = {1, -1, 0, 0};

int solution(vector<string> board) {
    int ans = -1;
    
    int n = board.size();
    int m = board[0].size();
    
    pair<int, int> start = {0, 0};
    pair<int, int> goal = {0, 0};
    
    vector<vector<int>> visited(n, vector<int>(m, -1));
    
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            if (board[y][x] == 'R')
            {
                start = {y, x};
            }
            else if (board[y][x] == 'G')
            {
                goal = {y, x};
            }
        }
    }
    
    queue<pair<int, int>> bfsQ;
    bfsQ.push(start);
    visited[start.first][start.second] = 0;
    
    while (!bfsQ.empty())
    {
        auto [sy, sx] = bfsQ.front();
        bfsQ.pop();
        
        bool flag = false;
        
        for (int d = 0; d < 4; d++)
        {
            int ny = sy;
            int nx = sx;
            
            while (true)
            {
                int nexty = ny + DY[d];
                int nextx = nx + DX[d];
                
                if (nexty < 0 || nexty >= n || nextx < 0 || nextx >= m)
                    break;
                    
                if (board[nexty][nextx] == 'D')
                    break;
                
                ny = nexty;
                nx = nextx;
            }
            
            if (ny == sy && nx == sx)
            {
                continue;
            }
            else if (visited[ny][nx] != -1)
            {
                continue;
            }
            else if (board[ny][nx] == 'G')
            {
                ans = visited[sy][sx] + 1;
                flag = true;
                break;
            }
            
            visited[ny][nx] = visited[sy][sx] + 1;
            bfsQ.push({ny, nx});
        }
        
        if (flag)
            break;
    }
    
    return ans;
}
