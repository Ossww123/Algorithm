#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int X[1000010];
    fill(X, X + 1000010, 9999999);
    X[1] = 0;

    for (int i = 1; i < 1000000; i++) {
        if (i + 1 <= 1000000) {
            X[i + 1] = min(X[i + 1], X[i] + 1);
        }
        if (2 * i <= 1000000) {
            X[2 * i] = min(X[2 * i], X[i] + 1);
        }
        if (3 * i <= 1000000) {
            X[3 * i] = min(X[3 * i], X[i] + 1);
        }
    }

    int N;
    cin >> N;
    cout << X[N];

    return 0;
}
