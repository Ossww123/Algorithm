#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, L;
    cin >> N >> L;

    vector<vector<int>> array(N, vector<int>(N, 0));
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> array[y][x];
        }
    }

    int ans = 0;

    // 가로 방향 검사
    for (int y = 0; y < N; y++) {
        bool isPossible = true;
        vector<bool> hasSlope(N, false); // 경사로가 이미 놓인 위치 체크

        for (int x = 1; x < N; x++) {
            // 높이 차이가 1보다 크면 불가능
            if (abs(array[y][x] - array[y][x - 1]) > 1) {
                isPossible = false;
                break;
            }

            // 이전 칸보다 현재 칸이 1 높은 경우 (오르막)
            if (array[y][x] - array[y][x - 1] == 1) {
                // L개의 연속된 동일 높이 칸이 있는지 확인
                int sameHeightCount = 0;
                for (int k = 1; k <= L; k++) {
                    if (x - k >= 0 && array[y][x - k] == array[y][x - 1] && !hasSlope[x - k]) {
                        sameHeightCount++;
                    }
                }

                if (sameHeightCount < L) {
                    isPossible = false;
                    break;
                }

                // 경사로 설치 표시
                for (int k = 1; k <= L; k++) {
                    hasSlope[x - k] = true;
                }
            }

            // 이전 칸보다 현재 칸이 1 낮은 경우 (내리막)
            else if (array[y][x - 1] - array[y][x] == 1) {
                // L개의 연속된 동일 높이 칸이 있는지 확인
                int sameHeightCount = 0;
                for (int k = 0; k < L; k++) {
                    if (x + k < N && array[y][x + k] == array[y][x] && !hasSlope[x + k]) {
                        sameHeightCount++;
                    }
                }

                if (sameHeightCount < L) {
                    isPossible = false;
                    break;
                }

                // 경사로 설치 표시
                for (int k = 0; k < L; k++) {
                    hasSlope[x + k] = true;
                }
            }
        }

        if (isPossible) {
            ans++;
        }
    }

    // 세로 방향 검사
    for (int x = 0; x < N; x++) {
        bool isPossible = true;
        vector<bool> hasSlope(N, false); // 경사로가 이미 놓인 위치 체크

        for (int y = 1; y < N; y++) {
            // 높이 차이가 1보다 크면 불가능
            if (abs(array[y][x] - array[y - 1][x]) > 1) {
                isPossible = false;
                break;
            }

            // 이전 칸보다 현재 칸이 1 높은 경우 (오르막)
            if (array[y][x] - array[y - 1][x] == 1) {
                // L개의 연속된 동일 높이 칸이 있는지 확인
                int sameHeightCount = 0;
                for (int k = 1; k <= L; k++) {
                    if (y - k >= 0 && array[y - k][x] == array[y - 1][x] && !hasSlope[y - k]) {
                        sameHeightCount++;
                    }
                }

                if (sameHeightCount < L) {
                    isPossible = false;
                    break;
                }

                // 경사로 설치 표시
                for (int k = 1; k <= L; k++) {
                    hasSlope[y - k] = true;
                }
            }

            // 이전 칸보다 현재 칸이 1 낮은 경우 (내리막)
            else if (array[y - 1][x] - array[y][x] == 1) {
                // L개의 연속된 동일 높이 칸이 있는지 확인
                int sameHeightCount = 0;
                for (int k = 0; k < L; k++) {
                    if (y + k < N && array[y + k][x] == array[y][x] && !hasSlope[y + k]) {
                        sameHeightCount++;
                    }
                }

                if (sameHeightCount < L) {
                    isPossible = false;
                    break;
                }

                // 경사로 설치 표시
                for (int k = 0; k < L; k++) {
                    hasSlope[y + k] = true;
                }
            }
        }

        if (isPossible) {
            ans++;
        }
    }

    cout << ans;

    return 0;
}