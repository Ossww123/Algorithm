#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool checkRunway(const vector<int>& row, int N, int X) {
    vector<bool> used(N, false);
    for (int i = 0; i < N - 1; i++) {
        
        // 높이가 2이상 차이나면 실패
        if (abs(row[i] - row[i + 1]) > 1) return false;

        // 높이가 같으면 다음으로 진행
        if (row[i] == row[i + 1]) continue;

        // 높이가 높아지면
        if (row[i] < row[i + 1]) {

            // i - (X-1) ~ i 까지 검사
            for (int j = i; j > i - X; j--) {
                if (j < 0 || row[j] != row[i] || used[j]) return false;
                used[j] = true;
            }
        }

        // 높이가 낮아지면
        else {

            // i+1 ~ i+X 까지 검사
            for (int j = i + 1; j < i + 1 + X; j++) {
                if (j >= N || row[j] != row[i + 1] || used[j]) return false;
                used[j] = true;
            }
        }
    }
    return true;
}

int solve() {
    int N, X;
    cin >> N >> X;

    vector<vector<int>> arr(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    int cnt = 0;

    // 가로줄(행)에 대해서 확인
    for (int i = 0; i < N; i++) {
        if (checkRunway(arr[i], N, X)) cnt++;
    }

    // 세로줄(열)에 대해서 확인
    for (int j = 0; j < N; j++) {
        vector<int> col(N);
        for (int i = 0; i < N; i++) {
            col[i] = arr[i][j];
        }
        if (checkRunway(col, N, X)) cnt++;
    }

    return cnt;
}

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int result = solve();
        cout << '#' << tc << ' ' << result << '\n';
    }

    return 0;
}