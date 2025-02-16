#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0;i < N;i++) {
        string str;
        cin >> str;

        if (str.length() >= 6 && str.length() <= 9) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }
    return 0;
}