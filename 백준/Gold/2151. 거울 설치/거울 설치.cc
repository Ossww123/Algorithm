#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::pair;

#include <string>
using std::string;

#include <algorithm>
using std::fill;
using std::max;

#include <vector>
using std::vector;

#include <queue>
using std::queue;

char matrix[50][51];
int distance[50][51];

int DY[4] = { 1, -1, 0, 0 };
int DX[4] = { 0, 0, -1, 1 };

queue<pair<int, int>> bfsQ;

int main()
{
    int N;
    cin >> N;

    for (int y = 0; y < N; ++y) {
        cin >> matrix[y];
    }

    int sy, sx;
    bool Flag = false;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            distance[y][x] = 9999;

            if (!Flag && '#' == matrix[y][x]) {
                sy = y;
                sx = x;
                matrix[y][x] = '.';
                Flag = true;
            }
        }
    }

    bfsQ.push({ sy, sx });
    distance[sy][sx] = 0;
    Flag = false;

    while (!bfsQ.empty()) {
        auto [y, x] = bfsQ.front();
        bfsQ.pop();

        for (int d = 0; d < 4; ++d) {
            int ny, nx, cy, cx;
            cy = y; cx = x;
            while (true) {
                ny = cy + DY[d];
                nx = cx + DX[d];

                // 경계를 벗어나면 중단
                if (ny < 0 || ny >= N || nx < 0 || nx >= N) break;

                // 벽을 만나면 중단
                if ('*' == matrix[ny][nx]) break;

                // 빈 공간이면 계속 이동
                if ('.' == matrix[ny][nx]) {
                    cy = ny;
                    cx = nx;
                    continue;
                }

                // 거울을 만나면 큐에 추가하고 계속 이동
                if ('!' == matrix[ny][nx]) {
                    if (distance[ny][nx] > distance[y][x] + 1) {
                        distance[ny][nx] = distance[y][x] + 1;
                        bfsQ.push({ ny, nx });
                    }
                    cy = ny;
                    cx = nx;
                    continue;
                }

                // 목적지를 만나면 결과 출력하고 종료
                if ('#' == matrix[ny][nx]) {
                    cout << distance[y][x];
                    Flag = true;
                    break;
                }
            }

            if (Flag) break;
        }

        if (Flag) break;
    }

    return 0;
}