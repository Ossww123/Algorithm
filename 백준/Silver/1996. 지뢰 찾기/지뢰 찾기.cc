#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int DY[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int DX[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int main()
{
    int N;
    cin >> N;

    vector<string> matrix(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> matrix[i];
    }

    vector<string> result(N);

    for (int i = 0; i < N; ++i)
    {
        result[i] = matrix[i];

        for (int j = 0; j < N; ++j)
        {
            result[i][j] = '0';

            if (matrix[i][j] == '.')
            {
                // 8방향 확인
                for (int d = 0; d < 8; ++d)
                {
                    int ny = i + DY[d];
                    int nx = j + DX[d];

                    if (ny >= 0 && ny < N && nx >= 0 && nx < N)
                    {
                        if (matrix[ny][nx] >= '0' && matrix[ny][nx] <= '9')
                        {
                            result[i][j] += (matrix[ny][nx] - '0');
                        }
                    }
                }

                if (result[i][j] > '9')
                {
                    result[i][j] = 'M';
                }
            }
            else
            {
                result[i][j] = '*';
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        cout << result[i] << endl;
    }

    return 0;
}