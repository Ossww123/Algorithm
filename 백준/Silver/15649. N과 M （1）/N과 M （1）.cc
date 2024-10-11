#include <iostream>
#include <vector>

using namespace std;

void backtracking(int N, int M, vector<int>& seq, vector<bool>& used) {
	if (seq.size() == M) {
		for (int i = 0; i < M; ++i) {
			cout << seq[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!used[i]) {
			used[i] = true;
			seq.push_back(i);
			backtracking(N, M, seq, used);
			seq.pop_back();
			used[i] = false;
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> seq;
	vector<bool> used(N + 1, false);

	backtracking(N, M, seq, used);

	return 0;
}