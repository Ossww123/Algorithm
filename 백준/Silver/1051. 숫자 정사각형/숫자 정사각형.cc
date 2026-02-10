#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N, M;

int main()
{
    cin >> N >> M;

    vector<vector<int>> matrix(N, vector<int>(M));

    for (int i = 0; i < N; i++)
    {
        string row;
        cin >> row;  // "12345"
        for (int j = 0; j < M; j++)
        {
            matrix[i][j] = row[j] - '0';
        }
    }

    for (int len = min(N, M); len >= 1; len--)
    {
        for (int y = 0; y + len - 1 < N; y++)
        {
            for (int x = 0; x + len - 1 < M; x++)
            {
                int t = y;
                int b = y + len - 1;
                int l = x;
                int r = x + len - 1;

                if (matrix[t][l] == matrix[t][r] &&
                    matrix[t][l] == matrix[b][l] &&
                    matrix[t][l] == matrix[b][r])
                {
                    cout << len * len;
                    return 0;
                }
            }
        }
    }

    return 0;
}
