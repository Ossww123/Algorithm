#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	string s;
	cin >> s;
	vector<int> v;
	for (char c : s)
	{
		v.push_back(c - '0');
	}
	sort(v.begin(), v.end());
	
	if (v[0] != 0)
	{
		cout << -1;
		return 0;
	}
	else
	{
		int sum = 0;
		for (int i : v)
		{
			sum += i;
		}
		if (sum % 3 != 0)
		{
			cout << -1;
			return 0;
		}
		else
		{
			for (int i = v.size() - 1; i >= 0; i--)
			{
				cout << v[i];
			}
		}
	}

	return 0;
}
