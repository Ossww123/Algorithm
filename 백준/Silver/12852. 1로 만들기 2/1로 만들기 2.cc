#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;
int dp[1000001];
int parent[1000001];

int main() {
    int n;
    cin >> n;

    fill(dp, dp + n + 1, -1);
    fill(parent, parent + n + 1, -1);

    dp[1] = 0;

    for (int i = 1; i < n; i++) {
        if (dp[i] == -1) continue;

        if (i * 2 <= n) {
            if (dp[i * 2] == -1 || dp[i * 2] > dp[i] + 1) {
                dp[i * 2] = dp[i] + 1;
                parent[i * 2] = i;
            }
        }

        if (i * 3 <= n) {
            if (dp[i * 3] == -1 || dp[i * 3] > dp[i] + 1) {
                dp[i * 3] = dp[i] + 1;
                parent[i * 3] = i;
            }
        }

        if (i + 1 <= n) {
            if (dp[i + 1] == -1 || dp[i + 1] > dp[i] + 1) {
                dp[i + 1] = dp[i] + 1;
                parent[i + 1] = i;
            }
        }
    }

    cout << dp[n] << '\n';

    int curr = n;
    while (curr != -1) {
        cout << curr << ' ';
        curr = parent[curr];
    }

    return 0;
}