#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int cnt = 0;
    int K = 1;
    while (N > 0) {
        if (K > N) {
            K = 1;
        }
        N -= K;
        cnt++;
        K++;
    }

    cout << cnt;

    return 0;
}