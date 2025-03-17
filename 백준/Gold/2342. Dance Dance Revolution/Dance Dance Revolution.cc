#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 발 위치에 따른 힘 계산
int calculatePower(int before, int after) {
    // before == 0 이라면 힘은 2
    if (before == 0) {
        return 2;
    }

    if (before == after) return 1;
    else if (abs(before - after) == 2) return 4;
    else return 3;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> orders;
    int order;
    while (1) {
        cin >> order;
        if (order == 0) break;
        orders.push_back(order);
    }

    int N = orders.size();
    if (N == 0) {
        cout << 0;
        return 0;
    }

    // dp[i][j] = i번째 단계에서 왼발이 i, 오른발이 j인 상태의 최소 힘
    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(5, vector<int>(5, 1e9)));

    // 초기 상태: 두 발 모두 0에 있음
    dp[0][0][0] = 0;

    // 상향식으로 dp 테이블 채우기
    for (int step = 0; step < N; step++) {
        int next = orders[step];

        for (int left = 0; left <= 4; left++) {
            for (int right = 0; right <= 4; right++) {
                if (dp[step][left][right] == 1e9) continue;

                // 왼발을 움직이는 경우 (단, 오른발과 같은 위치로는 이동 불가)
                if (next != right) {
                    dp[step + 1][next][right] = min(
                        dp[step + 1][next][right],
                        dp[step][left][right] + calculatePower(left, next)
                    );
                }

                // 오른발을 움직이는 경우 (단, 왼발과 같은 위치로는 이동 불가)
                if (next != left) {
                    dp[step + 1][left][next] = min(
                        dp[step + 1][left][next],
                        dp[step][left][right] + calculatePower(right, next)
                    );
                }
            }
        }
    }

    // 마지막 단계에서의 최소값 찾기
    int result = 1e9;
    for (int left = 0; left <= 4; left++) {
        for (int right = 0; right <= 4; right++) {
            result = min(result, dp[N][left][right]);
        }
    }

    cout << result;
    return 0;
}