#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int DX[4] = { 0, 0, 1, -1 };
int DY[4] = { 1, -1, 0 , 0 };

struct point {
    int y;
    int x;
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> paper;

    for (int y = 0; y < N; y++) {
        vector<int> row;
        for (int x = 0; x < M; x++) {
            int pic;
            cin >> pic;
            row.push_back(pic);
        }
        paper.push_back(row);
    }
    
    vector<vector<bool>> visited(N, vector<bool>(M, 0));

    queue<point> bfsQ;
    
    int cnt = 0;
    int max_space = 0;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (paper[y][x] == 0) continue;
            if (visited[y][x]) continue;
            
            cnt++;
            int space = 0;
            visited[y][x] = true;
            point p = { y, x };
            bfsQ.push(p);
            

            while (!bfsQ.empty()) {
                point s = bfsQ.front();
                bfsQ.pop();
                space++;

                for (int i = 0; i < 4; i++) {
                    int ny = s.y + DY[i];
                    int nx = s.x + DX[i];

                    if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                    if (!paper[ny][nx] || visited[ny][nx]) continue;

                    visited[ny][nx] = true;
                    bfsQ.push({ ny, nx });
                }
            }
            if (max_space < space) {
                max_space = space;
            }
        }
    }

    cout << cnt << endl << max_space;

    return 0;
}
