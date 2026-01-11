#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long double> x(N), y(N);

    for (int i = 0; i < N; i++)
    {
        cin >> x[i] >> y[i];
    }

    long double sum = 0;
    for (int i = 0; i < N; i++)
    {
        int j = (i + 1) % N;
        sum += x[i] * y[j] - y[i] * x[j];
    }

    long double area = fabsl(sum) / 2.0L;

    cout << fixed << setprecision(1) << area;
    return 0;
}
