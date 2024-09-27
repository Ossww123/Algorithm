#include <iostream>
using namespace std;

int n, m;
int A[100];

void f(int x, int y) {
    if (x == m) {
        for (int i = 0; i < m; i++) {
            cout << A[i];
            if (i < m - 1) cout << " ";
        }
        cout << endl;
        return;
    }

    for (int i = y; i <= n; i++) {
        A[x] = i;
        f(x + 1, i + 1);
    }
}

int main() {
    cin >> n >> m;
    f(0, 1);
    return 0;
}
