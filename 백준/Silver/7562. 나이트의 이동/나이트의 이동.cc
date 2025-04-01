#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <functional>
#include <queue>

using namespace std;

int DY[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int DX[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

struct Point {
    int y;
    int x;
    int value;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int I;
        cin >> I;

        vector<vector<int>> chessMap(I, vector<int>(I, -1));

        queue<Point> bfsQ;

        int sy, sx, ey, ex;
        cin >> sy >> sx;
        cin >> ey >> ex;

        chessMap[sy][sx] = 0;
        bfsQ.push({ sy, sx, 0 });

        int ans;
        while (!bfsQ.empty()) {
            Point start = bfsQ.front();
            int y = start.y;
            int x = start.x;
            int value = start.value;
            bfsQ.pop();

            if (y == ey && x == ex) {
                ans = value;
                break;
            }

            for (int i = 0; i < 8; i++) {
                int ny = y + DY[i];
                int nx = x + DX[i];

                if (ny >= I || nx >= I || ny < 0 || nx < 0) continue;
                if (chessMap[ny][nx] >= 0) continue;

                chessMap[ny][nx] = value;
                bfsQ.push({ ny, nx, value + 1 });
            }
        }

        cout << ans << endl;
    }

    return 0;
}