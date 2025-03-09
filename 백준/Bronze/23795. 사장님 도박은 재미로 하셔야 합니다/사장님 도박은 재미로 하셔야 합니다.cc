#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int sum = 0;
    while (true) {
        int N;
        cin >> N;
        if (N == -1)
            break;

        sum += N;
    }
    
    cout << sum;

    return 0;
}
