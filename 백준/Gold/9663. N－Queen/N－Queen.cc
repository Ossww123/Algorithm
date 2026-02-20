#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N;
int ans;
vector<int> row;
vector<int> col;
vector<int> diag1;
vector<int> diag2;

void DFS(int depth)
{
	if (depth == N)
	{
		ans++;
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (row[i] || col[i] || diag1[depth - i + N - 1] || diag2[depth + i])
			continue;

		row[i] = col[i] = diag1[depth - i + N - 1] = diag2[depth + i] = 1;
		DFS(depth + 1);
		row[i] = col[i] = diag1[depth - i + N - 1] = diag2[depth + i] = 0;
	}
}

int main()
{
	cin >> N;
	ans = 0;

	row.assign(N, 0);
	col.assign(N, 0);
	diag1.assign(2 * N - 1, 0); // 좌상 - 우하, -(N - 1) ~ (N - 1)
	diag2.assign(2 * N - 1, 0); // 우상 - 좌하, 0 ~ (2 * N - 2)

	DFS(0);

	cout << ans;

	return 0;
}
