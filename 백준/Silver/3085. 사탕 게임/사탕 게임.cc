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

#include <unordered_set>
using std::unordered_set;

int DY[4] = { 1, -1, 0, 0 };
int DX[4] = { 0, 0, -1, 1 };

int N;
char BOARD[50][51];

int ans;

void solve() {
    char temp = 0;
    int cnt = 0;

    // 가로 검사
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (0 == j) {
                temp = BOARD[i][j];
                cnt = 1;
            }
            else {
                if (temp == BOARD[i][j]) {
                    ++cnt;
                    ans = max(cnt, ans);
                }
                else {
                    temp = BOARD[i][j];
                    cnt = 1;
                }
            }
        }
    }

    // 세로 검사
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (0 == j) {
                temp = BOARD[j][i];
                cnt = 1;
            }
            else {
                if (temp == BOARD[j][i]) {
                    ++cnt;
                    ans = max(cnt, ans);
                }
                else {
                    temp = BOARD[j][i];
                    cnt = 1;
                }
            }
        }
    }
}

void change_and_solve() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N - 1; ++j) {
            char temp = BOARD[i][j + 1];
            if (temp == BOARD[i][j]) continue;

            BOARD[i][j + 1] = BOARD[i][j];
            BOARD[i][j] = temp;
            solve();
            BOARD[i][j] = BOARD[i][j + 1];
            BOARD[i][j + 1] = temp;
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N - 1; ++j) {
            char temp = BOARD[j + 1][i];
            if (temp == BOARD[j][i]) continue;

            BOARD[j + 1][i] = BOARD[j][i];
            BOARD[j][i] = temp;
            solve();
            BOARD[j][i] = BOARD[j + 1][i];
            BOARD[j + 1][i] = temp;
        }
    }
}

int main()
{
    ans = 1;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> BOARD[i];
    }

    change_and_solve();

    cout << ans;
    return 0;
}