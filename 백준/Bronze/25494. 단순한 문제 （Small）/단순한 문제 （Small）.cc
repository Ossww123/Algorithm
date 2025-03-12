#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;

        int cnt = 0;
        for (int i = 1;i <= a;i++) {
            for (int j = 1;j <= b;j++) {
                for (int k = 1;k <= c;k++) {
                    if ((i % j) == (j % k))
                        if ((j % k) == (k % i))
                            cnt++;
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}