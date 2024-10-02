#include <iostream>
#include <vector>
using namespace std;

const int DY[5] = { -1, 0, 0, 1, 0 };
const int DX[5] = { 0, 1, 0, 0, -1 };

int solve(int N, int M) {
	vector<vector<int>> matrix(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> matrix[i][j];
		}
	}

	int max_value = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			int total = 0;
			for (int k = 0; k < 5; k++) {
				int ny = y + DY[k];
				int nx = x + DX[k];
				if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
					total += matrix[ny][nx];
				}
			}
			if (total > max_value) {
				max_value = total;
			}
		}
	}

	return max_value;

}

int main(void) {
	
	int T;
	cin >> T;

	for (int tc = 1; tc < T + 1; tc++) {
		int N, M, answer;

		cin >> N >> M;
		answer = solve(N, M);

		cout << "#" << tc << " " << answer << endl;
	}

	return 0;
}