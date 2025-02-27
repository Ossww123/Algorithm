#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int max_value = -1;

    for (int i = 0;i < N;++i) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == b && b == c && c == a) {
            max_value = max(max_value, 10000 + a * 1000);
        }
        else if (a != b && b != c && c != a) {
            int temp = max({ a, b, c });
            max_value = max(max_value, temp*100);
        }
        else if (a == b) {
            max_value = max(max_value, 1000 + a * 100);
        }
        else if (b == c) {
            max_value = max(max_value, 1000 + b * 100);
        }
        else if (c == a) {
            max_value = max(max_value, 1000 + c * 100);
        }

    }

    cout << max_value;

    return 0;
}