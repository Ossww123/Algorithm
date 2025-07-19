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

int DX[4] = { 1, -1, 0, 0 };
int DY[4] = { 0, 0, 1, -1 };
char cLakeMap[1501][1501];
bool bSwanVisited[1501][1501];
queue<pair<int, int>> qWater;
queue<pair<int, int>> qSwan;
queue<pair<int, int>> qSwanNext;
int R, C;

int main()
{
    cin >> R >> C;

    for (int i = 0; i < R; ++i)
    {
        cin >> cLakeMap[i];
    }

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            if ('.' == cLakeMap[i][j])
            {
                qWater.push({ i, j });
            }
            else if ('L' == cLakeMap[i][j])
            {
                qWater.push({ i, j });
                if (qSwan.empty())
                {
                    qSwan.push({ i, j });
                    bSwanVisited[i][j] = true;
                }
            }
        }
    }

    int iDay = 0;
    bool bIsMeet = false;

    while (!bIsMeet) {
        while (!qSwan.empty() && !bIsMeet)
        {
            auto [y, x] = qSwan.front();
            qSwan.pop();

            for (int d = 0; d < 4; ++d)
            {
                int ny = y + DY[d];
                int nx = x + DX[d];

                if (ny < 0 || ny >= R || nx < 0 || nx >= C)
                    continue;

                if (bSwanVisited[ny][nx])
                    continue;

                if ('.' == cLakeMap[ny][nx])
                {
                    qSwan.push({ ny, nx });
                    bSwanVisited[ny][nx] = true;
                }
                else if ('X' == cLakeMap[ny][nx])
                {
                    qSwanNext.push({ ny, nx });
                    bSwanVisited[ny][nx] = true;
                }
                else if ('L' == cLakeMap[ny][nx])
                {
                    cout << iDay;
                    bIsMeet = true;
                    break;
                }
            }
        }

        ++iDay;

        qSwan = qSwanNext;
        while (!qSwanNext.empty()) qSwanNext.pop();

        int iWaterSize = qWater.size();
        for (int i = 0; i < iWaterSize; ++i)
        {
            auto [y, x] = qWater.front();
            qWater.pop();

            for (int d = 0; d < 4; ++d) {
                int ny = y + DY[d];
                int nx = x + DX[d];

                if (ny < 0 || ny >= R || nx < 0 || nx >= C)
                    continue;

                if ('X' == cLakeMap[ny][nx]) {
                    cLakeMap[ny][nx] = '.';
                    qWater.push({ ny, nx });
                }
            }
        }
    }

    return 0;
}