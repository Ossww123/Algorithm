#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<bool> broken_buttons(10, false);

    // 고장난 버튼 입력 받기
    for (int i = 0; i < M; i++) {
        int button;
        cin >> button;
        broken_buttons[button] = true;
    }

    // 기본값
    int min_cnt = abs(N - 100);
    int up = N, down = N;

    // 숫자 다 고장난 경우 결과는 기본값
    if (M == 10) {
        cout << min_cnt << endl;
        return 0;
    }

    auto can_press = [&](int num) {
        if (num == 0) return !broken_buttons[0];
        while (num > 0) {
            if (broken_buttons[num % 10]) return false;
            num /= 10;
        }
        return true;
        };

    // 모든 가능한 채널에 대해 확인
    for (int i = 0; i <= 1000000; i++) {
        if (can_press(i)) {
            int press = to_string(i).length() + abs(i - N);
            min_cnt = min(min_cnt, press);
        }
    }

    cout << min_cnt << endl;

    return 0;
}