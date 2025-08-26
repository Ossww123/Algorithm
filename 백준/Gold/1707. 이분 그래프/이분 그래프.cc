#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <stack>
using std::stack;

#include <algorithm>
using std::pair;

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> SetNum(V + 1, 0);
        vector<bool> visited(V + 1, false);

        vector<vector<int>> edges(V + 1);
        for (int i = 0; i < E; ++i) {
            int u, v;
            cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        bool isDisjointSet = true;

        for (int i = 1; i <= V; i++) {
            if (visited[i]) continue;

            stack<pair<int, bool>> stk;
            stk.push({ i, true });

            while (!stk.empty() && isDisjointSet) {
                auto [start, isFirstSet] = stk.top();
                stk.pop();

                visited[start] = true;
                SetNum[start] = isFirstSet ? 1 : 2;

                for (int next : edges[start]) {
                    if (SetNum[next] == SetNum[start]) {
                        isDisjointSet = false;
                        break;
                    }
                    if (visited[next]) continue;
                    stk.push({ next, !isFirstSet });
                }
            }
        }


        cout << (isDisjointSet ? "YES" : "NO") << '\n';
    }
    


    return 0;
}