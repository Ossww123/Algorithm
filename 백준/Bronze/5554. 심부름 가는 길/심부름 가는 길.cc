#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int total = a + b + c + d;
    cout << total / 60 << '\n' << total % 60;

    return 0;
}