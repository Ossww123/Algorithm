#include <iostream>

using namespace std;

int main()
{
	int N, F;
	int C = 0;

	cin >> N;

	int array[101];

	for (int i = 0; i < N; i++)
	{
		cin >> array[i];
	}

	cin >> F;

	for (int j = 0; j < N; j++)
	{
		if (array[j] == F)
		{
			C++;
		}
	}

	cout << C;

	return 0;
}