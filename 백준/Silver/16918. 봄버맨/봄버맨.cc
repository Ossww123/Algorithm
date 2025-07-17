#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::fill;
using std::string;
using std::max;

int DX[4] = { 1, -1, 0, 0 };
int DY[4] = { 0, 0, 1, -1 };


int main()
{
    int R, C, N;
    cin >> R >> C >> N;

    vector<vector<int>> vvMatrix(R, vector<int>(C, 0));

    for (int i = 0; i < R; ++i)
    {
        string sTemp;
        cin >> sTemp;

        for (int j = 0; j < C; ++j)
        {
            if ('O' == sTemp[j])
            {
                vvMatrix[i][j] = 2;
            }
        }
    }

    --N;
    vector<vector<int>> vvCopyMatrix = vvMatrix;
    while (N)
    {
        for (int i = 0; i < R; ++i)
        {
            for (int j = 0; j < C; ++j)
            {
                if (0 == vvMatrix[i][j])
                {
                    vvMatrix[i][j] = 3;
                }
                else if(2 == vvMatrix[i][j])
                {
                    vvMatrix[i][j] = 1;
                }
            }
        }
        
        --N;
        if (!N) break;

        for (int i = 0; i < R; ++i)
        {
            for (int j = 0; j < C; ++j)
            {
                vvCopyMatrix[i][j] = vvMatrix[i][j]-1;
            }
        }

        for (int i = 0; i < R; ++i)
        {
            for (int j = 0; j < C; ++j)
            {
                if (1 == vvMatrix[i][j])
                {
                    for (int D = 0; D < 4; ++D)
                    {
                        int ny = i + DY[D];
                        int nx = j + DX[D];
                        if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;

                        vvCopyMatrix[ny][nx] = 0;
                    }
                }
            }
        }

        vvMatrix = vvCopyMatrix;
        --N;
    }

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            if (vvMatrix[i][j])
            {
                cout << 'O';
            }
            else
            {
                cout << '.';
            }
        }

        cout << '\n';
    }

    return 0;
}