#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> edges[1010];
vector<bool> visited_dfs(1010, false);
vector<bool> visited_bfs(1010, false);

void DFS(int node) {
    visited_dfs[node] = true;
    cout << node << ' ';

    for (int i : edges[node]) {
        if (!visited_dfs[i]) {
            DFS(i);
        }
    }
}

void BFS(int node) {
    queue<int> bfsQ;
    bfsQ.push(node);
    visited_bfs[node] = true;
    cout << node << ' ';

    while (!bfsQ.empty()) {
        int start = bfsQ.front();
        bfsQ.pop();

        for (int i : edges[start]) {
            if (!visited_bfs[i]) {
                visited_bfs[i] = true;
                cout << i << ' ';
                bfsQ.push(i);
            }
        }
    }
}

int main() {
    int N, M, V;
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        sort(edges[i].begin(), edges[i].end());
    }

    DFS(V);
    cout << "\n";
    BFS(V);

    return 0;
}
