#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> edges[1010];
vector<bool> visited(1010, false);
int cnt = 0;

void DFS(int node) {
    visited[node] = true;

    for (int i : edges[node]) {
        if (!visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            cnt++;
            DFS(i);
        }
    }
    cout << cnt;

    return 0;
}
