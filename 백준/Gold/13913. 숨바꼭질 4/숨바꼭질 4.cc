#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <stack>
using std::stack;

#include <algorithm>
using std::pair;
using std::min;

#include <queue>
using std::queue;

int main() {
    int n, k;
    cin >> n >> k;

    if (n >= k) {
        cout << (n - k) << "\n";
        for (int x = n; x >= k; --x) {
            cout << x << ' ';
        }
    }
    else {
        vector<int> dist(100001, -1);
        vector<int> prev(100001, -1);
        queue<int> q;

        dist[n] = 0;
        q.push(n);

        while (!q.empty()) {
            int x = q.front();
            q.pop();

            if (x == k) {
                break;
            }

            int nx[3] = { x - 1, x + 1, x * 2 };

            for (int i = 0; i < 3; ++i) {
                int next = nx[i];

                if (next < 0 || next > 100000) continue;
                if (dist[next] != -1) continue;

                dist[next] = dist[x] + 1;
                prev[next] = x;
                q.push(next);
            }
        }
        vector<int> ans;
        for (int i = k; i != -1; i = prev[i]) {
            ans.push_back(i);
        }

        reverse(ans.begin(), ans.end());


        cout << dist[k] << "\n";
        for (size_t i = 0; i < ans.size(); ++i) {
            cout << ans[i] << ' ';
        }
    }


    return 0;
}