#include <iostream>
using namespace std;

int num[301];

int sum(int number)
{
	return num[number+1] * number;
}

int main()
{
	num[1] = 1;
	for (int i = 2; i < 302; i++)
	{
		num[i] = num[i - 1] + i;
	}

	int testcase,N,K;
	int result = 0;

	cin >> testcase;

	for (int i = 0; i < testcase; i++)
	{
		result = 0;
		cin >> N;
		K = N;
		for (int j = 0; j < N; j++)
		{
			result += sum(K);
			K--;
		}

		cout << result << endl;
	}

	return 0;
}