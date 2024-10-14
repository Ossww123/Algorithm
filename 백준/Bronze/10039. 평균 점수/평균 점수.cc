#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    int total = 0;
    if (a > 40) { total += a; }
    else { total += 40; }

    if (b > 40) { total += b; }
    else { total += 40; }

    if (c > 40) { total += c; }
    else { total += 40; }

    if (d > 40) { total += d; }
    else { total += 40; }

    if (e > 40) { total += e; }
    else { total += 40; }


    cout << total / 5;

    return 0;
}