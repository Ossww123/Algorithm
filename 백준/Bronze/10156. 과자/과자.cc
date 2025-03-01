#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;

    int ans = a * b - c;
    if (ans < 0)
        ans = 0;
    cout << ans;

    return 0;
}