#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board) {
    int n = board.size();
    const int INF = 1e9;
    vector<vector<vector<int>>> costs(n, vector<vector<int>>(n, vector<int>(4, INF)));

    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};

    struct Node { int y, x, dir, cost; };
    queue<Node> q;

    if (n > 1 && board[1][0] == 0) {
        costs[1][0][1] = 100;      // 아래
        q.push({1, 0, 1, 100});
    }
    if (n > 1 && board[0][1] == 0) {
        costs[0][1][3] = 100;      // 오른쪽
        q.push({0, 1, 3, 100});
    }

    while (!q.empty()) {
        auto [y, x, dir, cost] = q.front();
        q.pop();

        if (cost > costs[y][x][dir]) continue;

        for (int ndir = 0; ndir < 4; ndir++) {
            int ny = y + dy[ndir];
            int nx = x + dx[ndir];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            if (board[ny][nx] == 1) continue;

            int add = (ndir == dir ? 100 : 600);
            int ncost = cost + add;

            if (ncost < costs[ny][nx][ndir]) {
                costs[ny][nx][ndir] = ncost;
                q.push({ny, nx, ndir, ncost});
            }
        }
    }

    int answer = INF;
    for (int d = 0; d < 4; d++) {
        answer = min(answer, costs[n-1][n-1][d]);
    }
    return answer;
}
