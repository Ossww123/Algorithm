#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	vector<int> T(N+1);
	vector<int> P(N+1);

	for (int i = 1;i <= N;i++) {
		int t, p;
		cin >> t >> p;

		T[i] = t;
		P[i] = p;
	}

	vector<int> dp(N+1, 0); // n일차 완료했을 때 얻을 수 있는 최대 금액

	for (int i = 1;i <= N;i++) {
		int finish_day = i + T[i] - 1;
		if (finish_day <= N) {
			dp[finish_day] = max(dp[finish_day], dp[i-1] + P[i]);
		}
		dp[i] = max(dp[i], dp[i - 1]);
	}

	cout << dp[N];

	return 0;
}