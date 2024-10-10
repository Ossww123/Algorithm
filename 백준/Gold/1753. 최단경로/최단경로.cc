#include <iostream>
#include <vector>
#include <queue>
#include <utility> // pair
#include <algorithm> // fill
#include <functional>
#include <cstdio>
const int MAX_V = 20000;
const int INF = 1000000000;
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int V, E;
	cin >> V >> E;

	int K;
	cin >> K;
	vector<pair<int, int>> adj[MAX_V];
	K--;
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u - 1].emplace_back(v - 1, w);
	}
	int dist[MAX_V];
	fill(dist, dist + MAX_V, INF);
	bool visited[MAX_V] = { 0 };
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;

	dist[K] = 0;
	PQ.push(pair<int, int>(0, K));
	while (!PQ.empty()) {
		int curr;
		do {
			curr = PQ.top().second;
			PQ.pop();
		} while (!PQ.empty() && visited[curr]);

		if (visited[curr]) break;

		visited[curr] = true;

		for (auto &p : adj[curr]) {
			int next = p.first, d = p.second;
			if (dist[next] > dist[curr] + d) {
				dist[next] = dist[curr] + d;
				PQ.push(pair<int, int>(dist[next], next));
			}
		}
	}

	for (int i = 0; i < V; i++) {
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << '\n';
	}
	return 0;
}