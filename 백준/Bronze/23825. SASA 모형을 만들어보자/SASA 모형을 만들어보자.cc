#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    int cnt = 0;
    while (N >= 2 && M >= 2) {
        cnt++;
        N -= 2;
        M -= 2;
    }

    cout << cnt;

    return 0;
}