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

bool isValid(int row, int col, int N, int M) {
    return row >= 0 && row < N && col >= 0 && col < M;
}

bool isComplete(const vector<vector<int>> box, int N, int M) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            if (!box[row][col]) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    int M, N;
    cin >> M >> N;

    vector<vector<int>> box(N, vector<int>(M, 0));
    queue<Point> bfsQ;

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            cin >> box[row][col];
            if (box[row][col] == 1) {
                bfsQ.push({row, col});
            }
        }
    }

    int MAX_VAL = 1;

    while (!bfsQ.empty()) {
        int sy = bfsQ.front().y;
        int sx = bfsQ.front().x;
        bfsQ.pop();

        int ny, nx;
        for (int dir = 0; dir < 4; dir++) {
            ny = sy + DY[dir];
            nx = sx + DX[dir];

            if (!isValid(ny, nx, N, M)) {
                continue;
            }
            if (box[ny][nx]) {
                continue;
            }
            box[ny][nx] = box[sy][sx] + 1;
            if (box[ny][nx] > MAX_VAL) {
                MAX_VAL = box[ny][nx];
            }
            bfsQ.push({ ny, nx });
        }
    }

    if (isComplete(box, N, M)) {
        // 최종 출력은 -1한 값
        cout << MAX_VAL - 1;
    }
    else {
        cout << -1;
    }


    return 0;
}
