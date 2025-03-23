#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S;
    cin >> S;

    for (char c : S) {
        char ans = c - 'a' + 'A';
        cout << ans;
    }

    return 0;
}