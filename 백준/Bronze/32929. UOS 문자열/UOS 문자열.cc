#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    int N;
    cin >> N;

    int mod = N % 3;

    if (mod == 0) {
        cout << 'S';
    }
    else if (mod == 1) {
        cout << 'U';
    }
    else {
        cout << 'O';
    }
    

    return 0;
}
