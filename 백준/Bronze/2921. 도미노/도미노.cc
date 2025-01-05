#include <iostream>

using namespace std;

int DP[1010];

int main() {
    DP[1] = 3;

    for (int i = 2; i <= 1000; i++) {
        DP[i] = DP[i - 1] + i * (i + 1) + i * (i + 1) / 2;
    }
  
    int N;
    cin >> N;

    cout << DP[N];

    return 0;
}
