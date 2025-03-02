#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;

    int max_value = a + b + c;
    vector<int> cnts(max_value + 1, 0);
    for (int i = 1;i <= a; i++) {
        for (int j = 1;j <= b;j++) {
            for (int k = 1;k <= c;k++) {
                int num = i + j + k;
                cnts[num] = cnts[num] + 1;
            }
        }
    }

    int d = 0, e = 0;
    for (int i = 3;i <= max_value;i++) {
        if (cnts[i] > e) {
            e = cnts[i];
            d = i;
        }
    }

    cout << d;

    return 0;
}