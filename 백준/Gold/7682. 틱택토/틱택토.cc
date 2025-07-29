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
using std::min;
using std::find;

#include <vector>
using std::vector;

#include <queue>
using std::queue;

int DY[4] = { 1, -1, 0, 0 };
int DX[4] = { 0, 0, -1, 1 };

string ttt;

int cal_ans(char OX) {
    int ans = 0;
    for (int i = 0; i < 3; ++i) {
        if (ttt[i] == ttt[i + 3]
            && ttt[i + 3] == ttt[i + 6]
            && ttt[i] == OX)
            ++ans;

        if (ttt[3 * i] == ttt[3 * i + 1]
            && ttt[3 * i + 1] == ttt[3 * i + 2]
            && ttt[3 * i] == OX)
            ++ans;
    }

    if (ttt[0] == ttt[4]
        && ttt[4] == ttt[8]
        && ttt[0] == OX)
        ++ans;

    if (ttt[2] == ttt[4]
        && ttt[4] == ttt[6]
        && ttt[2] == OX)
        ++ans;

    return ans;
}

bool is_valid() {

    // 1. 갯수 체크
    int x_cnt = 0;
    int o_cnt = 0;
    for (int i = 0; i < 9; ++i) {
        if      (ttt[i] == 'X') ++x_cnt;
        else if (ttt[i] == 'O') ++o_cnt;
    }
    if (0 != x_cnt - o_cnt && 1 != x_cnt - o_cnt) return false;

    // 2. 둘 다 승리
    int x_ans = cal_ans('X');
    int o_ans = cal_ans('O');
    if (x_ans && o_ans) return false;

    bool a = o_ans;

    // 3. O가 이겼는데 X가 1개 더 많다.
    if (o_ans && x_cnt == o_cnt + 1) return false;

    // 4. X가 이겼는데 갯수가 같다.
    if (x_ans && x_cnt == o_cnt) return false;

    // 5. 게임이 안 끝났다.
    if (x_cnt + o_cnt != 9
        && x_ans + o_ans == 0) return false;

    return true;
}


int main()
{
    while (1) {
        cin >> ttt;
        if (ttt == "end") break;

        if (is_valid()) {
            cout << "valid\n";
        }
        else {
            cout << "invalid\n";
        }
    }
    return 0;
}