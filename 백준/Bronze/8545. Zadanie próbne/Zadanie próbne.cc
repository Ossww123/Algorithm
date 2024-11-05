#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    string T;
    cin >> T;

    reverse(T.begin(), T.end());

    cout << T;

    return 0;
}