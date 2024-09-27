#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> height(N);
	for (int i = 0; i < N; i++)
		cin >> height[i];

	
	int lo = 0, hi = 0;
	for (int i = 0; i < N; i++) {
		if (height[i] > hi) {
			hi = height[i];
		}
	}

	
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		
		long long sum = 0;
		for (int i = 0; i < N; i++)
			if (height[i] > mid) sum += height[i] - mid;

		
		if (sum >= M) lo = mid;
		
		else hi = mid;
	}

	cout << lo << endl;
}
