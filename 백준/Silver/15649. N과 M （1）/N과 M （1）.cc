#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> arr;
vector<bool> visited;

void dfs(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << (i + 1 == M ? '\n' : ' ');
        }
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        arr[depth] = i;
        dfs(depth + 1);
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    arr.assign(M, 0);
    visited.assign(N + 1, false);

    dfs(0);
    return 0;
}