#include <string>
#include <vector>
#include <queue>

using namespace std;

int DX[4] = {0, 0, -1, 1};
int DY[4] = {1, -1, 0, 0};

int solution(vector<string> storage, vector<string> requests) {
    int N = storage.size();
    int M = storage[0].size();
    
    vector<vector<char>> newStorage(N+2, vector<char>(M+2, '-'));
    for (int i=1; i<N+1; i++) {
        for (int j=1; j<M+1; j++) {
            newStorage[i][j] = storage[i-1][j-1];
        }
    }
    
    int r = requests.size();
    for (int q=0; q<r; q++) {
        if (requests[q].size() == 1) {
            vector<vector<char>> tempStorage = newStorage;
            vector<vector<bool>> visited(N+2, vector<bool>(M+2, false));
            
            queue<pair<int, int>> bfsQ;
            bfsQ.push({0, 0});
            visited[0][0] = true;
            
            while (!bfsQ.empty()) {
                int y = bfsQ.front().first;
                int x = bfsQ.front().second;
                bfsQ.pop();
                
                for (int dir=0; dir<4; dir++) {
                    int ny = y + DY[dir];
                    int nx = x + DX[dir];
                    
                    if (ny >= N+2 || ny < 0 || nx >= M+2 || nx < 0) continue;
                    if (visited[ny][nx]) continue;
                    
                    if (tempStorage[ny][nx] == requests[q][0]) {
                        newStorage[ny][nx] = '-';
                    }
                    else if (tempStorage[ny][nx] == '-') {
                        bfsQ.push({ny, nx});
                        visited[ny][nx] = true;
                    }
                }
            }
        }
        else {
            for (int i=0; i<N+2; i++) {
                for (int j=0; j<M+2; j++) {
                    if (newStorage[i][j] == requests[q][0]) {
                        newStorage[i][j] = '-';
                    }
                }
            }
        }
    }
    
    int answer = 0;
    for (int i=0; i<N+2; i++) {
        for (int j=0; j<M+2; j++) {
            if (newStorage[i][j] != '-') answer++;
        }
    }
    return answer;
}