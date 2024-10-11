#include <iostream>
#include <cstdint>

using namespace std;

int main() {
    for (int t = 0; t < 3; t++) {
        int N;
        cin >> N;

        __int128 sum = 0;
        for (int i = 0; i < N; i++) {
            int64_t x;
            cin >> x;
            sum += x;
        }

        if (sum > 0) cout << "+\n";
        else if (sum < 0) cout << "-\n";
        else cout << "0\n";
    }
    return 0;
}