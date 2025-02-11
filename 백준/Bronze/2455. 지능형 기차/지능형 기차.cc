#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int D, U;
    int people=0;
    int max_val = 0;

    while (1) {
        cin >> D >> U;
        people -= D;
        people += U;

        max_val = max(max_val, people);

        if (U == 0) break;
    }

    cout << max_val;

    return 0;
}