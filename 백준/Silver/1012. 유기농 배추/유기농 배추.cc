#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int DX[4] = { 0, 0, 1, -1 };
int DY[4] = { 1, -1, 0, 0 };

struct Point {
    int y;
    int x;
};

int main() {
    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++) {
        int M, N, K;
        int cnt = 0;
        cin >> M >> N >> K;

        vector<vector<int>> matrix(N, vector<int>(M, 0));

        for (int i = 0; i < K; i++) {
            int cabx, caby;
            cin >> cabx >> caby;
            matrix[caby][cabx] = 1;
        }

        vector<vector<bool>> visited(N, vector<bool>(M, 0));

        queue<Point> Q;

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (!matrix[y][x]) {
                    continue;
                }
                if (visited[y][x]) {
                    continue;
                }

                cnt++;

                Q.push({ y, x });
                visited[y][x] = 1;

                while (!Q.empty()) {
                    Point P = Q.front();
                    Q.pop();

                    for (int i = 0; i < 4; i++) {
                        int dy = P.y + DY[i];
                        int dx = P.x + DX[i];

                        if (dy < 0 || dy >= N || dx < 0 || dx >= M) {
                            continue;
                        }
                        if (!matrix[dy][dx] || visited[dy][dx]) {
                            continue;
                        }

                        visited[dy][dx] = 1;
                        Q.push({ dy, dx });
                    }
                }
            }
        }
        cout << cnt << endl;

    }

    return 0;
}
