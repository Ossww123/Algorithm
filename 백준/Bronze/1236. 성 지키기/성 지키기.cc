#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N, M;

    cin >> N >> M;

    string castle[50];

    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        castle[i] = row;
    }

    int cntR = 0;
    int cntC = 0;
    // 행 검사
    for (int y = 0; y < N; y++) {
        bool isempty = true;
        for (int x = 0; x < M; x++) {
            if (castle[y][x] == 'X') {
                isempty = false;
                break;
            }
        }
        if (isempty) {
            cntR++;
        }
    }

    // 열 검사
    for (int x = 0; x < M; x++) {
        bool isempty = true;
        for (int y = 0; y < N; y++) {
            if (castle[y][x] == 'X') {
                isempty = false;
                break;
            }
        }
        if (isempty) {
            cntC++;
        }
    }

    if (cntR > cntC) {
        cout << cntR;
    }
    else {
        cout << cntC;
    }

    return 0;
}
