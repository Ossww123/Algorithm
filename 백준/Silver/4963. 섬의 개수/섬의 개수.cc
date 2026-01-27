#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int DY[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int DX[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int main() {
	while (true)
	{
		int w, h;
		cin >> w >> h;

		if (w == 0 && h == 0)
			break;

		vector<vector<int>> board(h, vector<int>(w));
		vector<vector<bool>> visited(h, vector<bool>(w, false));

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> board[i][j];
			}
		}

		int islandCount = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (board[i][j] == 1 && !visited[i][j])
				{
					islandCount++;
					visited[i][j] = true;
					vector<pair<int, int>> stack;
					stack.push_back({ i, j });

					while (!stack.empty())
					{
						pair<int, int> current = stack.back();
						stack.pop_back();

						for (int dir = 0; dir < 8; dir++)
						{
							int ny = current.first + DY[dir];
							int nx = current.second + DX[dir];

							if (ny >= 0 && ny < h && nx >= 0 && nx < w)
							{
								if (board[ny][nx] == 1 && !visited[ny][nx])
								{
									visited[ny][nx] = true;
									stack.push_back({ ny, nx });
								}
							}
						}
					}
				}
			}
		}

		cout << islandCount << endl;
	}
}
