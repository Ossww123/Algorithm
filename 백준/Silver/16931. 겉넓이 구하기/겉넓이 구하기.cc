#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> shape(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> shape[i][j];
        }
    }

    int ans = 0;

    // 밑면 윗면
    ans += 2 * N * M;

    // 좌우
    for (int i = 0; i < N; ++i) {
        ans += shape[i][0];

        for (int j = 0; j < M - 1; ++j) {
            ans += std::abs(shape[i][j] - shape[i][j + 1]);
        }

        ans += shape[i][M - 1];
    }

    // 앞뒤
    for (int j = 0; j < M; ++j) {
        ans += shape[0][j];

        for (int i = 0; i < N - 1; ++i) {
            ans += std::abs(shape[i][j] - shape[i + 1][j]);
        }

        ans += shape[N - 1][j];
    }

    cout << ans;

    return 0;
}