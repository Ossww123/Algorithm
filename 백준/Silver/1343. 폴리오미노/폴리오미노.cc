#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string poly;
    cin >> poly;

    string result = "";
    bool possible = true;
    int cnt = 0;
    for (char c : poly) {
        if (c == 'X') {
            cnt++;
            if (cnt == 4) {
                result += "AAAA";
                cnt = 0;
            }
        }
        else {
            if (cnt == 0) {
                result += ".";
            }
            else if (cnt == 2) {
                result += "BB.";
                cnt = 0;
            }
            else {
                possible = false;
                break;
            }
        }
    }
    
    if (cnt == 2) {
        result += "BB";
    }
    else if (cnt != 0) {
        possible = false;
    }

    if (possible) {
        cout << result;
    }
    else {
        cout << -1;
    }

    return 0;
}