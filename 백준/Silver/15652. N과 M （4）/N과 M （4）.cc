#include <iostream>
#include <vector>

using namespace std;

void backtracking(int N, int M, vector<int>& seq, int idx) {
	if (seq.size() == M) {
		for (int i = 0; i < M; i++) {
			cout << seq[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (i >= idx) {
			seq.push_back(i);
			backtracking(N, M, seq, i);
			seq.pop_back();
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> seq;
	// vector<bool> used(N + 1, false);

	backtracking(N, M, seq, 0);

	return 0;
}