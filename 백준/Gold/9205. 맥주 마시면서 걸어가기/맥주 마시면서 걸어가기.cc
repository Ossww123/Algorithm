#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<pair<int, int>> nodes;
        vector<vector<int>> edges(N+2, vector<int>(N+2, 0));

        for (int i = 0;i < N + 2;i++) {
            int x, y;
            cin >> x >> y;
            nodes.push_back({ x, y });
        }

        for (int i = 0;i < N + 2;i++) {
            for (int j = 0;j < N + 2;j++) {
                int dist = abs(nodes[i].first - nodes[j].first) + abs(nodes[i].second - nodes[j].second);
                edges[i][j] = dist;
                edges[j][i] = dist;
            }
        }

        vector<bool> visited(N + 2, false);

        queue<int> bfsQ;
        bfsQ.push(0);
        visited[0] = true;

        while (!bfsQ.empty()) {
            int start_node = bfsQ.front();
            bfsQ.pop();

            for (int i = 0;i < N + 2;i++) {
                if (edges[start_node][i] > 1000) continue;
                if (visited[i] == true) continue;

                bfsQ.push(i);
                visited[i] = true;
            }
        }

        if (visited[N + 1]) {
            cout << "happy" << endl;
        }
        else {
            cout << "sad" << endl;
        }

    }

    return 0;
}