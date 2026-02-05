#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int DY[4] = {0, 0, 1, -1};
int DX[4] = {1, -1, 0, 0};

int main()
{
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> matrix(N, vector<int>(M, 0));

    for (int i = 0; i < K; i++)
    {
        int lbx, lby, rtx, rty;
        cin >> lbx >> lby >> rtx >> rty;

        for (int y = lby; y < rty; y++)
        {
            for (int x = lbx; x < rtx; x++)
            {
                matrix[y][x] = 1;
            }
        }
    }

    int ans = 0;
    vector<int> spaceAns;
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            if (matrix[y][x] == 1) continue;
            if (visited[y][x]) continue;

            ans++;
            visited[y][x] = true;

            queue<pair<int, int>> Q;
            Q.push({y, x});

            int space = 1;

            while (!Q.empty())
            {
                int cy = Q.front().first;
                int cx = Q.front().second;
                Q.pop();

                for (int d = 0; d < 4; d++)
                {
                    int ny = cy + DY[d];
                    int nx = cx + DX[d];

                    if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                    if (visited[ny][nx]) continue;
                    if (matrix[ny][nx] == 1) continue;

                    visited[ny][nx] = true;
                    Q.push({ny, nx});
                    space++;
                }
            }

            spaceAns.push_back(space);
        }
    }

    sort(spaceAns.begin(), spaceAns.end());

    cout << ans << '\n';
    for (int s : spaceAns)
    {
        cout << s << ' ';
    }

    return 0;
}
