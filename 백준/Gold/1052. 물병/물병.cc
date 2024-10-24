#include <iostream>

using namespace std;

int check_one(int num) {
    int cnt = 0;
    while (num != 0) {
        if (num & 1)
            cnt++;
        num >>= 1;
    }

    return cnt;
}

int main() {
    int N, K;
    cin >> N >> K;
    
    // 2진수로 바꿨을 때 1이 몇개 있는지 확인
    int curr;
    int cnt = 0;
    while (true) {
        curr = check_one(N);
        if (K >= curr)
            break;

        // K보다 1이 많다면 1L물통 하나 추가
        N++;
        cnt++;
    }

    cout << cnt << endl;

    return 0;
}