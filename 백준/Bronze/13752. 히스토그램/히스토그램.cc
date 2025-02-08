#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++) {
            cout << '=';
        }
        cout << '\n';
    }

    return 0;
}