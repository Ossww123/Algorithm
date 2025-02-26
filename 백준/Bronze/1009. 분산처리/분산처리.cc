#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    while (N--) {
        int a, b, ans = 1;
        cin >> a >> b;

        for (int i = 0; i < b; i++) {
            ans = (ans * a) % 10;
        }

        if (ans > 0) {
            cout << ans << '\n';
        }
        else {
            cout << 10 << '\n';
        }
    }
    
    return 0;
}
