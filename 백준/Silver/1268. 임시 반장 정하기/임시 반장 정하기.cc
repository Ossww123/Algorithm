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

    vector<vector<int>> students(N, vector<int>(5, 0));

    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < 5; ++x)
        {
            cin >> students[y][x];
        }
    }

    vector<int> counts(N, 0);

    for (int student = 0; student < N; ++student)
    {
        vector<bool> isSame(N);
        int count = 0;

        for (int i = 0; i < N; ++i)
        {
            if (i == student)   continue;
            if (isSame[i])      continue;

            for (int classLevel = 0; classLevel < 5; ++classLevel)
            {
                if (students[i][classLevel] == students[student][classLevel])
                {
                    isSame[i] = true;
                    ++count;
                    break;
                }
            }
        }

        counts[student] = count;
    }

    int answer = 0;
    int maxCount = 0;
    for (int i = N - 1; i >= 0; --i)
    {
        if (maxCount <= counts[i])
        {
            maxCount = counts[i];
            answer = i + 1;
        }
    }

    cout << answer;

    return 0;
}