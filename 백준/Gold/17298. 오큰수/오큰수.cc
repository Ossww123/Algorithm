#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> nums(N);
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}

	vector<int> ans(N, -1);
	stack<int> stk;

	for (int i = N - 1; i >= 0; i--)
	{
		while (true)
		{
			if (stk.empty())
			{
				ans[i] = -1;
				stk.push(nums[i]);
				break;
			}

			int s = stk.top();
			if (s > nums[i])
			{
				ans[i] = s;
				stk.push(nums[i]);
				break;
			}
			else
			{
				stk.pop();
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << ans[i] << ' ';
	}

	return 0;
}