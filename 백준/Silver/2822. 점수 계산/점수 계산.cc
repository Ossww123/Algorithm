#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Score {
	int score;
	int index;
};

int main() {
	Score scores[8];
	for (int i = 0; i < 8; i++) {
		cin >> scores[i].score;
		scores[i].index = i + 1;
	}

	// 내림차순 정렬 (score 기준)
	sort(scores, scores + 8, [](const Score& a, const Score& b) {
		return a.score > b.score;  // a.score가 b.score보다 클 경우 true 반환 (내림차순)
	});

	int total=0;
	for (int i = 0; i < 5; i++) {
		total += scores[i].score;
	}

	cout << total << endl;

	int includedProblem[5];
	for (int i = 0; i < 5; i++) {
		includedProblem[i] = scores[i].index;
	}
	sort(includedProblem, includedProblem + 5, [](const int a, const int b) {
		return a < b;
	});

	for (int i = 0; i < 5; i++) {
		cout << includedProblem[i] << ' ';
	}

	return 0;
}
