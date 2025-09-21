#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int bfs(vector<string>& mat, int sX, int sY, int H, int W) {
    vector<vector<int>> dist(H, vector<int>(W, -1));
    queue<pair<int, int>> bfsQ;

    bfsQ.push({ sX, sY });
    dist[sX][sY] = 0;

    int maxDist = 0;

    while (!bfsQ.empty()) {
        int x = bfsQ.front().first;
        int y = bfsQ.front().second;
        bfsQ.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < H && ny >= 0 && ny < W &&
                mat[nx][ny] == 'L' && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                bfsQ.push({ nx, ny });
                maxDist = max(maxDist, dist[nx][ny]);
            }
        }
    }

    return maxDist;
}

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> mat(H);
    for (int i = 0; i < H; i++) {
        cin >> mat[i];
    }

    int maxDist = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (mat[i][j] == 'L') {
                int dist = bfs(mat, i, j, H, W);
                maxDist = max(maxDist, dist);
            }
        }
    }

    cout << maxDist;

    return 0;
}