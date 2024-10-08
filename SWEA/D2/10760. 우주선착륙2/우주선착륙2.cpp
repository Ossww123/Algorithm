#include <iostream>
#include <vector>

using namespace std;

const int dx[8] = { 1, 1, 1, 0, -1, -1, -1, 0 };
const int dy[8] = { 1, 0, -1, -1, -1, 0, 1, 1 };

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc < T + 1; tc++) {
		int N, M;
		int result = 0;
		cin >> N >> M;
		vector<vector<int>> matrix(N, vector<int>(M));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> matrix[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int cnt = 0;
				for (int dir = 0; dir < 8; dir++) {
					int ny = i + dy[dir];
					int nx = j + dx[dir];

					if (ny < 0 | ny >= N | nx < 0 | nx >= M) {
						continue;
					}

					if (matrix[ny][nx] < matrix[i][j]) {
						cnt++;
					}
				}

				if (cnt >= 4) {
					result++;
				}
			}
		}
		cout << '#' << tc << ' ' << result << endl;

	}

	return 0;
}