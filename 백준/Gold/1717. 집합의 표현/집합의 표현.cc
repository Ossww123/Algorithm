#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

struct DSU
{
	vector<int> parent, size;

	DSU(int n)
	{
		parent.resize(n);
		size.resize(n, 1);
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	int find(int a)
	{
		if (parent[a] == a)
			return a;
		parent[a] = find(parent[a]);
		return parent[a];
	}

	void unite(int a, int b)
	{
		a = find(a);
		b = find(b);
		if (a != b)
		{
			if (size[a] < size[b])
				swap(a, b);
			parent[b] = a;
			size[a] += size[b];
		}
	}

	bool same(int a, int b)
	{
		return find(a) == find(b);
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	DSU dsu(N + 1);
	for (int i = 0; i < M; i++)
	{
		int q, a, b;
		cin >> q >> a >> b;
		if (q == 1)
		{
			if (dsu.same(a, b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else
		{
			dsu.unite(a, b);
		}
	}

	return 0;
}
