#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>

using namespace std;

struct State {
    pair<int, int> R;
    pair<int, int> B;
    int turn;
};

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

pair<int, int> move_ball(vector<string>& matrix, int y, int x, int dir) {
    while (true) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (matrix[ny][nx] == '#') { break; }

        y = ny; x = nx;

        if (matrix[y][x] == 'O') { break; }
    }

    return { y, x };
}

pair<pair<int, int>, pair<int, int>> tilt(vector<string>& matrix, int ry, int rx, int by, int bx, int dir) {
    pair<int, int> temp_r = move_ball(matrix, ry, rx, dir);
    pair<int, int> temp_b = move_ball(matrix, by, bx, dir);
    
    if (temp_r == temp_b && matrix[temp_r.first][temp_r.second] != 'O') {
        int dist_r = abs(temp_r.first - ry) + abs(temp_r.second - rx);
        int dist_b = abs(temp_b.first - by) + abs(temp_b.second - bx);
        
        if (dist_r > dist_b) {
            temp_r.first -= dy[dir];
            temp_r.second -= dx[dir];
        } else {
            temp_b.first -= dy[dir];
            temp_b.second -= dx[dir];
        }
    }
    
    return { temp_r, temp_b };
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> matrix(n);

    for (int i = 0; i < n; i++) {
        cin >> matrix[i];
    }

    int s_bx, s_by, s_rx, s_ry;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 'R') {
                s_ry = i; s_rx = j;
                matrix[i][j] = '.';
            }
            else if (matrix[i][j] == 'B') {
                s_by = i; s_bx = j;
                matrix[i][j] = '.';
            }
        }
    }

    int ans = -1;
    queue<State> bfsQ;
    set<pair<pair<int, int>, pair<int, int>>> visited;
    
    bfsQ.push({ {s_ry, s_rx }, { s_by, s_bx }, 0 });
    visited.insert({{s_ry, s_rx}, {s_by, s_bx}});

    while (!bfsQ.empty()) {
        State current = bfsQ.front();
        bfsQ.pop();

        int ry = current.R.first, rx = current.R.second;
        int by = current.B.first, bx = current.B.second;
        int turn = current.turn;

        if (turn >= 10) { continue; }

        for (int dir = 0; dir < 4; dir++) {
            pair<pair<int, int>, pair<int, int>> result = tilt(matrix, ry, rx, by, bx, dir);
            pair<int, int> new_r = result.first;
            pair<int, int> new_b = result.second;

            int nry = new_r.first, nrx = new_r.second;
            int nby = new_b.first, nbx = new_b.second;

            if (matrix[nby][nbx] == 'O') {
                continue;
            }

            if (matrix[nry][nrx] == 'O') {
                ans = turn + 1;
                cout << ans << endl;
                return 0;
            }

            if (visited.find({{nry, nrx}, {nby, nbx}}) != visited.end()) {
                continue;
            }

            visited.insert({{nry, nrx}, {nby, nbx}});
            bfsQ.push({ {nry, nrx}, {nby, nbx}, turn + 1 });
        }
    }

    cout << ans << endl;
    return 0;
}