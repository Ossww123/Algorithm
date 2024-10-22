#include <iostream>
#include <string>
using namespace std;

int main() {
    string num;
    cin >> num;
    int length = num.length();

    if (length > 1) {
        bool found = false;
        for (int i = 1; i < length; i++) {
            int left = 1;
            int right = 1;

            for (int index = 0; index < i; index++) {
                left *= (num[index] - '0');
            }

            for (int index = i; index < length; index++) {
                right *= (num[index] - '0');
            }

            if (left == right) {
                cout << "YES" << endl;
                found = true;
                break;
            }
        }
        
        if (!found) {
            cout << "NO" << endl;
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}