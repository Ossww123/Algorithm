#include <iostream>

using namespace std;

void solve(int N) {
	int dp[11];  // N은 최대 10
	dp[0] = 1;   // ()
	dp[1] = 1;   // (1)
	dp[2] = 2;   // (1+1, 2)
	dp[3] = 4;   // (1+1+1, 1+2, 2+1, 3)

	for (int i = 4; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	cout << dp[N] << endl;
}

int main() {
	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		int N;
		cin >> N;
		solve(N);
	}
}
