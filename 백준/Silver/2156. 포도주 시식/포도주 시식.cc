#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> wines(N+1);
    for (int i=1; i <= N; i++) {
        int wine;
        cin >> wine;
        wines[i] = wine;
    }

    vector<int> DP(N+1); // N번까지 마실 수 있는 최대의 양
    DP[1] = wines[1];
    
    if (N > 1)
        DP[2] = wines[1] + wines[2];

    if (N > 2) {
        DP[3] = max({ DP[2], wines[1] + wines[3], wines[2] + wines[3] });
    }

    if (N > 3) {
        for (int i = 4; i <= N; i++) {
            // i-2, i-1번을 마신 경우 | i-2, i번을 마신 경우 | i-1, i번을 마신 경우
            DP[i] = max({ DP[i - 1], DP[i - 2] + wines[i], DP[i - 3] + wines[i - 1] + wines[i] });
        }
    }
    
    cout << DP[N];

    return 0;
}