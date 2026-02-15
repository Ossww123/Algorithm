#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Result
{
	int minusOne, zero, one;
};

Result DevideAndConquer(vector<vector<int>>& matrix, int x, int y, int size)
{
	if (size == 1)
	{
		Result result = { 0,0,0 };
		if (matrix[y][x] == -1)
			result.minusOne = 1;
		else if (matrix[y][x] == 0)
			result.zero = 1;
		else
			result.one = 1;

		return result;
	}
	

	int first = matrix[y][x];
	int newSize = size / 3;
	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (matrix[i][j] != first)
			{
				Result count = { 0,0,0 };
				for (int k = 0; k < 3; k++)
					for (int l = 0; l < 3; l++)
					{
						Result divCount = DevideAndConquer(matrix, x + l * newSize, y + k * newSize, newSize);
						count.minusOne += divCount.minusOne;
						count.zero += divCount.zero;
						count.one += divCount.one;
					}

				return count;
			}
		}
	}

	Result result = { 0,0,0 };
	if (matrix[y][x] == -1)
		result.minusOne = 1;
	else if (matrix[y][x] == 0)
		result.zero = 1;
	else
		result.one = 1;

	return result;
}

int main()
{
	int N;
	cin >> N;

	vector<vector<int>> matrix(N, vector<int>(N));
	for(int i=0; i<N;i++ )
		for (int j = 0; j < N; j++)
			cin >> matrix[i][j];

	Result result = DevideAndConquer(matrix, 0, 0, N);
	cout << result.minusOne << endl;
	cout << result.zero << endl;
	cout << result.one << endl;


	return 0;
}
