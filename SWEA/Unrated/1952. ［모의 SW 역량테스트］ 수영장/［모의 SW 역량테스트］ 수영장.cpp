#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <map>
#include <tuple>

using namespace std;

int solve() {
	int oneday, onemonth, threemonth, oneyear;
	cin >> oneday >> onemonth >> threemonth >> oneyear;
	
	int use_plan[12];

	for (int i = 0; i < 12; i++) {
		cin >> use_plan[i];
	}

	// '1일 이용권 * 이용 일 수'와 '1달 이용권'중 싼 거 입력
	int month_value[12];

	for (int i = 0; i < 12; i++) {
		if (use_plan[i] * oneday <= onemonth){
			month_value[i] = use_plan[i] * oneday;
		}
		else {
			month_value[i] = onemonth;
		}
	}
	
	int dp[12];
	dp[0] = month_value[0];
	dp[1] = dp[0] + month_value[1];
	dp[2] = min(dp[1] + month_value[2], threemonth);

	for (int i = 3; i < 12; i++) {
		dp[i] = min(dp[i - 3] + threemonth, dp[i - 1] + month_value[i]);
	}

	int total_value;
	total_value = min(dp[11], oneyear);

	return total_value;
}

int main() {
	int T;
	cin >> T;
	
	for (int tc = 1; tc <= T; tc++) {
		int min_value = solve();

		cout << '#' << tc << ' ' << min_value << '\n';
	}

	return 0;
}