#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<vector<pair<int, int>>> adjList(N + 1);

    for (int i = 0; i < N - 1; i++) {
        int p, q, r;
        cin >> p >> q >> r;
        adjList[p].emplace_back(q, r);
        adjList[q].emplace_back(p, r);
    }

    for (int i = 0; i < Q; i++) {
        int K, V;
        cin >> K >> V;

        vector<bool> visited(N + 1, false);
        queue<int> bfsQ;
        bfsQ.push(V);
        visited[V] = true;

        int cnt = 0;
        while (!bfsQ.empty()) {
            int current = bfsQ.front();
            bfsQ.pop();

            for (pair<int, int> edge : adjList[current]) {
                int next = edge.first;
                int usado = edge.second;
                if (!visited[next] && usado >= K) {
                    visited[next] = true;
                    bfsQ.push(next);
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}