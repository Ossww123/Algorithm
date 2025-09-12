#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int T, W;
    cin >> T >> W;

    vector<int> plum_pos(T + 1);
    for (int i = 1; i <= T; i++) {
        cin >> plum_pos[i];
    }

    // dp[y][x] y번 움직이고 x초에 받은 자두 개수
    vector<vector<int>> dp(W + 1, vector<int>(T + 1, 0));

    // 안움직였을때
    for (int x = 1; x <= T; ++x) {
        dp[0][x] = plum_pos[x] == 1 ? dp[0][x - 1] + 1 : dp[0][x - 1];
    }
    
    for (int y = 1; y <= W; ++y) {
        for (int x = 1; x <= T; ++x) {
            int curr_pos = (y % 2) == 0 ? 1 : 2;
            int plus_point = curr_pos == plum_pos[x] ? 1 : 0;

            dp[y][x] = max(dp[y][x - 1] + plus_point, dp[y - 1][x - 1] + plus_point);
        }
    }

    int ans = 0;
    for (int i = 0; i <= W; ++i) {
        ans = max(ans, dp[i][T]);
    }

    cout << ans;

    return 0;
}