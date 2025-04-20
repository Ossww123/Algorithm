#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

int DY[4] = {0,0,1,-1};
int DX[4] = {1,-1,0,0};

int solution(vector<vector<int>> land) {
    int N = land.size();
    int M = land[0].size();
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<pair<int, int>> bfsQ;
    vector<int> oilValues(M, 0);
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if (visited[i][j]) continue;
            if (!land[i][j]) continue;
            
            bfsQ.push({i,j});
            visited[i][j] = true;
            
            unordered_set<int> xPoints;
            xPoints.insert(j);
            
            int cnt = 0;
            
            while (!bfsQ.empty()){
                int sy = bfsQ.front().first;
                int sx = bfsQ.front().second;
                bfsQ.pop();
                cnt++;
                
                for (int dir=0;dir<4;dir++){
                    int ny = sy + DY[dir];
                    int nx = sx + DX[dir];
                    
                    if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                    if (visited[ny][nx]) continue;
                    if (!land[ny][nx]) continue;
                    
                    bfsQ.push({ny, nx});
                    visited[ny][nx] = true;
                    xPoints.insert(nx);
                }
            }
            
            for (int x:xPoints){
                oilValues[x] += cnt;
            }
        }
    }
    
    int answer = 0;
    answer = *max_element(oilValues.begin(), oilValues.end());
    return answer;
}