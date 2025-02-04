#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;
    b = 100 - b;

    int c = a * b;
    if (c >= 10000) {
        cout << 0;
    }
    else {
        cout << 1;
    }

    return 0;
}