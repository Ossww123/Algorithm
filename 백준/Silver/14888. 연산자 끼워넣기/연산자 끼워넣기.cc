#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> A;
int op[4];
int MAX_VALUE = -1000000000;
int MIN_VALUE = 1000000000;

void dfs(int idx, int cur)
{
    if (idx == N)
    {
        MAX_VALUE = max(MAX_VALUE, cur);
        MIN_VALUE = min(MIN_VALUE, cur);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (op[i] == 0)
            continue;
        op[i]--;

        int nxt = cur;
        if (i == 0)
            nxt = cur + A[idx];
        else if (i == 1)
            nxt = cur - A[idx];
        else if (i == 2)
            nxt = cur * A[idx];
        else if (i == 3)
            nxt = cur / A[idx];

        dfs(idx + 1, nxt);

        op[i]++;
    }
}

int main() {
    cin >> N;
    A.resize(N);
    
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    
    for (int i = 0; i < 4; i++)
    {
        cin >> op[i];
    }

    dfs(1, A[0]);

    cout << MAX_VALUE << endl << MIN_VALUE;
    return 0;
}
