#include <iostream>
using namespace std;

int main() {
    while (1) {
        float a, b;
        cin >> a >> b;

        if (a == 0 && b == 0) {
            cout << "AXIS";
            break;
        }

        else if (a == 0 || b == 0) {
            cout << "AXIS";
        }

        else if (a > 0 && b > 0) {
            cout << "Q1";
        }

        else if (a < 0 && b > 0) {
            cout << "Q2";
        }

        else if (a < 0 && b < 0) {
            cout << "Q3";
        }

        else if (a > 0 && b < 0) {
            cout << "Q4";
        }

        cout << endl;
    }

    return 0;
}
