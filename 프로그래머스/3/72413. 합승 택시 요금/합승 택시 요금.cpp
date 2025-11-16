#include <bits/stdc++.h>
using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, 1e8));

    for (int i = 1; i <= n; ++i) {
        dist[i][i] = 0;
    }

    for (auto &f : fares) {
        int u = f[0], v = f[1], w = f[2];
        dist[u][v] = w;
        dist[v][u] = w;
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            if (dist[i][k] == 1e8) continue;
            for (int j = 1; j <= n; ++j) {
                if (dist[k][j] == 1e8) continue;
                int nd = dist[i][k] + dist[k][j];
                if (nd < dist[i][j]) {
                    dist[i][j] = nd;
                }
            }
        }
    }

    int answer = 1e8;
    for (int k = 1; k <= n; ++k) {
        int cost = dist[s][k] + dist[k][a] + dist[k][b];
        if (cost < answer) answer = cost;
    }

    return answer;
}
