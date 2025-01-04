#include <iostream>
#include <vector>

#define MAX 1010

using namespace std;

vector<int> edges[MAX];
vector<bool> visited(MAX, false);
int cnt;

// 초기화 함수
void init(int N) {
    for (int i = 1; i <= N; i++) {
        edges[i].clear();
    }
    fill(visited.begin(), visited.end(), false);
    cnt = 0;
}

void dfs(int start) {
    visited[start] = true;

    for (int node : edges[start]) {

        if (!visited[node]) {
            dfs(node);
        }
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        init(N); // 초기화 함수

        for (int i = 1; i <= N; i++) {
            int num;
            cin >> num;
            edges[i].push_back(num);
            edges[num].push_back(i);
        }

        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                cnt++;
                dfs(i);
            }
        }

        cout << cnt << endl;
    }

    return 0;
}
