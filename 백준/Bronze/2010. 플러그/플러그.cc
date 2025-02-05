#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int result = 0;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        result += (temp - 1);
    }

    cout << result + 1;

    return 0;
}