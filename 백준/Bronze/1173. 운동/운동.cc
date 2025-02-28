#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, m, M, T, R;
    cin >> N >> m >> M >> T >> R;

    int curr = m;

    if (m + T > M) {
        cout << -1;
    }
    else {
        int cnt = 0;
        int minute = 0;
        while (cnt < N) {
            if (curr + T <= M) {
                curr += T;
                cnt++;
            }
            else {
                curr -= R;
                if (curr < m) {
                    curr = m;
                }
            }

            minute++;
        }

        cout << minute;
    }
    return 0;
}