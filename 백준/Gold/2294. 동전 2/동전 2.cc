#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <stack>
using std::stack;

#include <algorithm>
using std::pair;
using std::min;

#include <queue>
using std::queue;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    // dp[i] i원 만드는데 필요한 최소 동전 개수
    vector<int> dp(10001, 99999);
    dp[0] = 0;

    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j < n; ++j) {
            if (0 <= (i - coins[j]) && dp[i-coins[j]] != -1) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    cout << (dp[k] != 99999 ? dp[k] : -1);
    

    return 0;
}