#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int temp = N % 8;

    if (temp == 1)
        cout << 1;
    else if (temp == 2 || temp == 0)
        cout << 2;
    else if (temp == 3 || temp == 7)
        cout << 3;
    else if (temp == 4 || temp == 6)
        cout << 4;
    else if (temp == 5)
        cout << 5;

    return 0;
}