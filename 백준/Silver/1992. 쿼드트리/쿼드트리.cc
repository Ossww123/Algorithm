#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N;
vector<string> matrix;

void DivideAndConquer(int x, int y, int size)
{
	if (size == 1)
	{
		cout << matrix[y][x];
		return;
	}

	char first = matrix[y][x];
	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (matrix[i][j] != first)
			{
				cout << "(";
				DivideAndConquer(x, y, size / 2);
				DivideAndConquer(x + size / 2, y, size / 2);
				DivideAndConquer(x, y + size / 2, size / 2);
				DivideAndConquer(x + size / 2, y + size / 2, size / 2);
				cout << ")";
				return;
			}
		}
	}
	cout << first;
}

int main()
{
	cin >> N;

	matrix.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> matrix[i];
	}

	DivideAndConquer(0, 0, N);

	return 0;
}
