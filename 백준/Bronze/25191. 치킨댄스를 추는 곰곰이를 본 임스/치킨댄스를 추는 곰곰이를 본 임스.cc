#include <iostream>

using namespace std;

int main()
{
    int N, C, B;
    cin >> N >> C >> B;

    int total = 0;
    total += (C / 2 + B);

    if (N < total) {
        total = N;
    }

    cout << total;

    return 0;
}
