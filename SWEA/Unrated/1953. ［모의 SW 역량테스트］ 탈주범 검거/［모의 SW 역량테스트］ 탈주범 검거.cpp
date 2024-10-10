#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <map>
#include <tuple>

using namespace std;

const int MAX_N = 50;
const int MAX_M = 50;
const int DY[4] = { -1, 1, 0, 0 };
const int DX[4] = { 0, 0, -1, 1 };

map<int, tuple<bool, bool, bool, bool>> pipes;

void initializePipes() {
	// 1 : up down left right
	// 2 : up down
	// 3 : left right
	// 4 : up right
	// 5 : down right
	// 6 : down left
	// 7 : up left
	pipes[1] = make_tuple(true, true, true, true);
	pipes[2] = make_tuple(true, true, false, false);
	pipes[3] = make_tuple(false, false, true, true);
	pipes[4] = make_tuple(true, false, false, true);
	pipes[5] = make_tuple(false, true, false, true);
	pipes[6] = make_tuple(false, true, true, false);
	pipes[7] = make_tuple(true, false, true, false);
}

int solve() {
	int N, M, holeY, holeX, times;
	cin >> N >> M >> holeY >> holeX >> times;

	int matrix[MAX_N][MAX_M];
	int visited[MAX_N][MAX_M];

	for (int i = 0; i < MAX_N; i++) {
		fill(matrix[i], matrix[i] + MAX_M, -1);
		fill(visited[i], visited[i] + MAX_M, -1);
	}

	

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> matrix[i][j];
		}
	}

	queue<pair<int, int>> q;
	q.push({ holeY, holeX });
	visited[holeY][holeX] = 1;

	while (!q.empty()) {
		auto curr = q.front();
		q.pop();

		int sy = curr.first;
		int sx = curr.second;

		if (visited[sy][sx] >= times) {
			continue;
		}

		for (int i = 0; i < 4; i++) {
			if (i == 0) {
				if (bool is_possible = !get<0>(pipes[matrix[sy][sx]])) {
					continue;
				}
			}
			else if (i == 1) {
				if (bool is_possible = !get<1>(pipes[matrix[sy][sx]])) {
					continue;
				}
			}
			else if (i == 2) {
				if (bool is_possible = !get<2>(pipes[matrix[sy][sx]])) {
					continue;
				}
			}
			else if (i == 3) {
				if (bool is_possible = !get<3>(pipes[matrix[sy][sx]])) {
					continue;
				}
			}

			int ny = sy + DY[i];
			int nx = sx + DX[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M) {
				continue;
			}

			if (visited[ny][nx] > 0) {
				continue;
			}

			if (i == 0) {
				if (bool is_possible = !get<1>(pipes[matrix[ny][nx]])) {
					continue;
				}
			} else if (i == 1) {
				if (bool is_possible = !get<0>(pipes[matrix[ny][nx]])) {
					continue;
				}
			} else if (i == 2) {
				if (bool is_possible = !get<3>(pipes[matrix[ny][nx]])) {
					continue;
					}
			} else if (i == 3) {
				if (bool is_possible = !get<2>(pipes[matrix[ny][nx]])) {
					continue;
				}
			}

			visited[ny][nx] = visited[sy][sx] + 1;
			q.push({ ny, nx });

		}	

	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] > 0) { cnt++; }
		}
	}

	return cnt;
}

int main() {
	initializePipes();

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int num_hidable;
		num_hidable = solve();

		cout << '#' << tc << ' ' << num_hidable << '\n';
	}

	return 0;
}