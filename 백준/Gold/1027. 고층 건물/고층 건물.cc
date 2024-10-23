#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int main() {
	int N;
	cin >> N;

	int buildings[50] = { 0 };
	int cnt[50] = { 0 };
	for (int i = 0; i < N; i++)
		cin >> buildings[i];

	for (int i = 0; i < N; i++) {
		double max_level = -9999999999;
		for (int j = i + 1; j < N; j++) {
			double level = (double)(buildings[j] - buildings[i]) / (j - i);
			if (level > max_level) {
				cnt[i]++;
				cnt[j]++;
				max_level = level;
			}
		}
	}

	int res = 0;

	for (auto elem : cnt)
		res = max(res, elem);
	cout << res << '\n';
	return 0;
}