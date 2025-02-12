#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ax, ay, az;
    int cx, cy, cz;
    cin >> ax >> ay >> az >> cx >> cy >> cz;


    cout << cx - az << ' ' << cy / ay << ' ' << cz - ax;

    return 0;
}