#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a;
    cin >> a;

    if (a == 1 || a == 3) {
        cout << -1;
    }
    else {
        int b = a / 10;
        int c = a % 10;

        if (c == 1) {
            cout << b * 2 - 2 + 4;
        }
        else if (c == 2) {
            cout << b * 2 + 1;
        }
        else if (c == 3) {
            cout << b * 2 -2 + 5;
        }
        else if (c == 4) {
            cout << b * 2 + 2;
        }
        else if (c == 5) {
            cout << b * 2 + 1;
        }
        else if (c == 6) {
            cout << b * 2 + 3;
        }
        else if (c == 7) {
            cout << b * 2 + 2;
        }
        else if (c == 8) {
            cout << b * 2 + 4;
        }
        else if (c == 9) {
            cout << b * 2 + 3;
        }
        else if (c == 0) {
            cout << b * 2;
        }
    }


    return 0;
}