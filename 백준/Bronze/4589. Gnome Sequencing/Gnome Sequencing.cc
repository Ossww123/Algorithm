#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    cout << "Gnomes:" << endl;
    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a > b) {
            if (b > c) {
                cout << "Ordered" << endl;
            }
            else {
                cout << "Unordered" << endl;
            }
        }
        if (a < b) {
            if (b < c) {
                cout << "Ordered" << endl;
            }
            else {
                cout << "Unordered" << endl;
            }
        }
    }

    return 0;
}
