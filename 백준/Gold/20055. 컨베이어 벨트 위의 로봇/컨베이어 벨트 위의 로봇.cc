#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::pair;

#include <string>
using std::string;

#include <algorithm>
using std::fill;
using std::max;

#include <vector>
using std::vector;

#include <queue>
using std::queue;

int DY[4] = { 1, -1, 0, 0 };
int DX[4] = { 0, 0, -1, 1 };

int belt_drb[201];
bool have_robot[201];

int main()
{
    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= 2 * N; ++i) {
        cin >> belt_drb[i];
    }

    int head = 1;
    int tail = N;
    fill(have_robot + 1, have_robot + 2 * N + 1, false);

    int level = 0;
    while (1) {
        ++level;

        // 1. 한 칸 회전 (시계방향)
        head = (head == 1) ? 2 * N : head - 1;
        tail = (tail == 1) ? 2 * N : tail - 1;

        // 내리는 위치에 있는 로봇 제거
        if (have_robot[tail]) {
            have_robot[tail] = false;
        }

        // 2. 로봇 이동
        for (int i = tail; i != head; i = (i == 1) ? 2 * N : i - 1) {
            if (have_robot[i]) {
                int next = (i == 2 * N) ? 1 : i + 1;
                if (!have_robot[next] && belt_drb[next] >= 1) {
                    have_robot[i] = false;
                    have_robot[next] = true;
                    --belt_drb[next];
                }
            }
        }

        // 내리는 위치에 있는 로봇 제거
        if (have_robot[tail]) {
            have_robot[tail] = false;
        }

        // 3. 로봇 올리기
        if (!have_robot[head] && belt_drb[head] >= 1) {
            have_robot[head] = true;
            --belt_drb[head];
        }

        // 4. 내구도 0인 칸 체크
        int zero_drb_count = 0;
        for (int i = 1; i <= 2 * N; ++i) {
            if (belt_drb[i] == 0) ++zero_drb_count;
        }

        if (zero_drb_count >= K) break;
    }

    cout << level;

    return 0;
}