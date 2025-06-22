#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> ropes(N);

    for (int i=0;i<N;++i)
    {
        cin >> ropes[i];
    }

    sort(ropes.begin(), ropes.end());

    int answer = 0;
    for (int i = 0; i < N; ++i)
    {
        answer = max(answer, ropes[i] * (N - i));
    }

    cout << answer;
    return 0;
}