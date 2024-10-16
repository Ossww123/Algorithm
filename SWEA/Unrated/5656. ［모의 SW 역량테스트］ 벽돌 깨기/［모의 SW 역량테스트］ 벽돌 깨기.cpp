#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int DY[4] = { 0, 0, 1, -1 };
const int DX[4] = { 1, -1, 0, 0 };

void block_down(int H, int W, vector<vector<int>>& matrix) {
    for (int x = 0; x < W; x++) {
        int write = H - 1;
        for (int y = H - 1; y >= 0; y--) {
            if (matrix[y][x] > 0) {
                matrix[write][x] = matrix[y][x];
                if (write != y) matrix[y][x] = 0;
                write--;
            }
        }
    }
}

int cal_block_num(int H, int W, const vector<vector<int>>& matrix) {
    int block_num = 0;
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            if (matrix[y][x] > 0) block_num++;
        }
    }
    return block_num;
}

struct Point {
    int y, x, boom_power;
};

void BFS(int H, int W, vector<vector<int>>& matrix, int shoot_line) {
    int start = -1;
    for (int y = 0; y < H; y++) {
        if (matrix[y][shoot_line] > 0) {
            start = y;
            break;
        }
    }
    
    if (start == -1) return;

    queue<Point> que;
    que.push({ start, shoot_line , matrix[start][shoot_line] });
    matrix[start][shoot_line] = 0;

    while (!que.empty()) {
        auto [sy, sx, power] = que.front();
        que.pop();

        for (int k = 1; k < power; k++) {
            for (int i = 0; i < 4; i++) {
                int ny = sy + DY[i] * k;
                int nx = sx + DX[i] * k;

                if (ny < 0 || ny >= H || nx < 0 || nx >= W || matrix[ny][nx] == 0) continue;
                que.push({ ny, nx, matrix[ny][nx] });
                matrix[ny][nx] = 0;
            }
        }
    }

    block_down(H, W, matrix);
}

void solve(int N, int H, int W, vector<vector<int>>& matrix, int cnt, int& min_value) {
    if (cnt == N || cal_block_num(H, W, matrix) == 0) {
        min_value = min(min_value, cal_block_num(H, W, matrix));
        return;
    }

    vector<vector<int>> original = matrix;
    for (int x = 0; x < W; x++) {
        BFS(H, W, matrix, x);
        solve(N, H, W, matrix, cnt + 1, min_value);
        matrix = original;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int N, W, H;
        cin >> N >> W >> H;

        vector<vector<int>> matrix(H, vector<int>(W));

        for (int y = 0; y < H; y++) {
            for (int x = 0; x < W; x++) {
                cin >> matrix[y][x];
            }
        }

        int min_value = 0x7FFFFFFF;
        solve(N, H, W, matrix, 0, min_value);

        cout << '#' << tc << ' ' << min_value << '\n';
    }

    return 0;
}