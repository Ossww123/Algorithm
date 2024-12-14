#include <iostream>

using namespace std;

int main() {

    int DP[1001];

    // 자신의 차례에서 남은 돌이 i개 일 때, 1이면 승리확정, 2면 패배확정
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 1;

    for (int i = 4; i <= 1000; i++) {

        // 자기 턴에 돌을 가져가고, 상대턴에서 남은돌이 승리밖에 없다면
        if (DP[i - 1] == 1 && DP[i - 3] == 1) {
            DP[i] = 2;
        }
        else {
            DP[i] = 1;
        }
    }

    int N;
    cin >> N;

    if (DP[N] == 1) {
        cout << "SK";
    }
    else {
        cout << "CY";
    }

    return 0;
}
