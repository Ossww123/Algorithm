#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    int N;
    cin >> N;

    string currTxt;
    string nextTxt;
    int len = 0;
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            cin >> currTxt;
            len = currTxt.size();
        }
        else {
            cin >> nextTxt;
            for (int j = 0; j < len; j++) {
                if (currTxt[j] == '?') {
                    continue;
                }
                else if (currTxt[j] == nextTxt[j]) {
                    continue;
                }
                else {
                    currTxt[j] = '?';
                }
            }
        }
    }

    cout << currTxt;
    

    return 0;
}
