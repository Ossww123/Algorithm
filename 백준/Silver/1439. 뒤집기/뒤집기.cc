#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int DY[4] = { -1,0,1,0 }; // 북, 동, 남, 서 방향
int DX[4] = { 0,1,0,-1 };


int main() {
    
    string S;
    cin >> S;

    int n = S.length();

    int cntZero = 0;
    int cntOne = 0;

    // 전부 0으로 바꾸기
    for (int i = 0; i < n; i++) {
        if (S[i] == '1') {
            if (i == 0 || S[i - 1] == '0') {
                cntZero++;
            }
        }
    }

    // 전부 1로 바꾸기
    for (int i = 0; i < n; i++) {
        if (S[i] == '0') {
            if (i == 0 || S[i - 1] == '1') {
                cntOne++;
            }
        }
    }

    int answer = min(cntZero, cntOne);
    cout << answer << endl;

    return 0;

    return 0;
}