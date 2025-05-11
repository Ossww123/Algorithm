#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int DY[4] = { -1,0,1,0 }; // 북, 동, 남, 서 방향
int DX[4] = { 0,1,0,-1 };

int dn(int constructor) {
    int ret = constructor;
    while (constructor) {
        ret += constructor % 10;
        constructor /= 10;
    }

    return ret;
}

int main() {
    vector<bool> isSelf(10001, true);

    for (int i = 1; i < 10000; i++) {
        int selfNum = dn(i);
        if (selfNum > 10000) continue;
        isSelf[selfNum] = false;
    }

    for (int i = 1; i <= 10000; i++) {
        if (isSelf[i]) {
            cout << i << '\n';
        }
    }
    return 0;
}