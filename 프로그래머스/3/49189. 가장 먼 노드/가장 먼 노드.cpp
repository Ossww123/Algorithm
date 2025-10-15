#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> graph(n + 1);
    for (auto& e : edge) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }

    vector<int> dist(n + 1, -1);

    queue<int> q;
    q.push(1);
    dist[1] = 0;

    int maxDist = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int next : graph[curr]) {
            if (dist[next] == -1) {
                dist[next] = dist[curr] + 1;
                maxDist = max(maxDist, dist[next]);
                q.push(next);
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == maxDist) {
            answer++;
        }
    }

    return answer;
}