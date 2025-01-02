#include <iostream>
#include <vector>
#include <stack>

#define MAX_V 101

using namespace std;

vector<int> edges[MAX_V];
bool visited[MAX_V];
int cnt = 0;

void dfs(int node) {
    visited[node] = true;

    for (int i : edges[node]) {

        if (!visited[i]) {
            cnt++;
            dfs(i);
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    dfs(1);

    cout << cnt;

    return 0;
}
