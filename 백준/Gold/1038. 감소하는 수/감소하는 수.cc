#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<string> s;

	stack<string> stk;

	for (int i = 0; i <= 9; i++)
	{
		string temp = to_string(i);
		stk.push(temp);
		s.push_back(temp);
	}

	while (!stk.empty())
	{
		string temp = stk.top();
		stk.pop();
		char last = temp[temp.size() - 1];
		for (int i = 0; i <= 9; i++)
		{
			if (last - '0' <= i) continue;
			string newTemp = temp + to_string(i);
			stk.push(newTemp);
			s.push_back(newTemp);
		}
	}

	sort(s.begin(), s.end(), [](string a, string b) {
		if (a.size() == b.size()) return a < b;
		return a.size() < b.size();
		});

	int size = s.size();
	if (N >= size) {
		cout << -1;
		return 0;
	}

	cout << s[N];

	return 0;
}
