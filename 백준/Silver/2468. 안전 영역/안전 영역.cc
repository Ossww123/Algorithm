#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

int DY[4] = { 0, 0, 1, -1 };
int DX[4] = { 1, -1, 0, 0 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    int max_height = 0;
    vector<vector<int>> area(N, vector<int>(N));
    for (int i = 0;i < N;i++) {
        for (int j = 0;j < N;j++) {
            int height;
            cin >> height;
            area[i][j] = height;
            if (height > max_height) max_height = height;
        }
    }

    int ans = 0;
    for (int level = 0;level <= max_height;level++) {
        queue<pair<int, int>> bfsQ;
        int safeArea = 0;
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        for (int y = 0;y < N;y++) {
            for (int x = 0;x < N;x++) {
                if (visited[y][x]) continue;
                if (area[y][x] <= level) continue;

                safeArea++;
                visited[y][x] = true;
                bfsQ.push({ y, x });

                while (!bfsQ.empty()) {
                    int sy = bfsQ.front().first;
                    int sx = bfsQ.front().second;
                    bfsQ.pop();

                    for (int dir = 0;dir < 4;dir++) {
                        int ny = sy + DY[dir];
                        int nx = sx + DX[dir];

                        if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                        if (visited[ny][nx]) continue;
                        if (area[ny][nx] <= level) continue;

                        visited[ny][nx] = true;
                        bfsQ.push({ ny, nx });
                    }
                }
            }
        }

        if (safeArea > ans) ans = safeArea;
    }

    cout << ans;

    return 0;
}