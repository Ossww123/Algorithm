#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>
using std::min;

typedef long long ll;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    // dp[방문한도시][i] = 해당하는 도시들을 방문하고 현재 도시 i에 있을 때의 최소 비용
    vector<vector<int>> dp(1 << n, vector<int>(n, 10000001));

    // 0번도시(1<<0) 에서 출발 (비용 0)
    dp[1][0] = 0;

    // u번 도시에서 v번 도시로 가는 계산
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int u = 0; u < n; u++) {

            // u번 도시를 방문한 경우가 아니거나 불가능한 경로인 경우 제외
            if (!(mask & (1 << u)) || dp[mask][u] == 10000001) continue;

            for (int v = 0; v < n; v++) {
                // v번 도시를 이미 방문했거나 u==v 인 경우(또는 갈 수 없는 경우) 제외
                if (mask & (1 << v) || cost[u][v] == 0) continue;

                int n_mask = mask | (1 << v);
                dp[n_mask][v] = min(dp[n_mask][v], dp[mask][u] + cost[u][v]);
            }
        }
    }

    // 모든 도시 방문 + (마지막 도시 -> 시작점) 계산
    int full_bitmask = (1 << n) - 1;
    int result = 10000001;

    for (int i = 1; i < n; i++) {
        if (dp[full_bitmask][i] != 10000001 && cost[i][0] != 0) {
            result = min(result, dp[full_bitmask][i] + cost[i][0]);
        }
    }

    cout << result;

    return 0;
}