#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>

using namespace std;

int main()
{
	int N, L;
	cin >> N >> L;

	bool found = false;
	while (L <= 100)
	{
		int sum = 0;
		// N = d + (d + 1) + (d + 2) + ... + (d + L - 1) = L * d + (L - 1) * L / 2
		// d = (N - (L - 1) * L / 2) / L
		if ((N - (L - 1) * L / 2) % L == 0)
		{
			int d = (N - (L - 1) * L / 2) / L;
			if (d >= 0) {
				for (int i = 0; i < L; i++)
					cout << d + i << " ";
				found = true;
				break;
			}
		}
		L++;
	}

	if (!found)
	{
		cout << -1;
	}

	return 0;
}
