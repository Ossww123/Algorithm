#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 100001;

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> time(MAX, -1);
	vector<int> count(MAX, 0);
	queue<int> q;

	q.push(N);
	time[N] = 0;
	count[N] = 1;

	while (!q.empty()) {
		int current = q.front();
		q.pop();

		if (current == K) {
			cout << time[K] << "\n";
			cout << count[K] << "\n";
			return 0;
		}

		vector<int> next_positions = { current - 1, current + 1, current * 2 };

		for (int next : next_positions) {
			if (next < 0 || next >= MAX) continue;

			if (time[next] == -1) {
				time[next] = time[current] + 1;
				count[next] = count[current];
				q.push(next);
			}
			else if (time[next] == time[current] + 1) {
				count[next] += count[current];
			}
		}
	}

	return 0;
}