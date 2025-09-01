#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <stack>
using std::stack;

#include <algorithm>
using std::pair;
using std::min;

#include <queue>
using std::queue;

int main() {
    int N;
    cin >> N;

    vector<vector<bool>> reach(N + 1, vector<bool>(N + 1, false));

    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        reach[a][b] = true;
    }

    for (int i = 1; i <= N; ++i) reach[i][i] = true;

    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (reach[i][k] && reach[k][j])
                    reach[i][j] = true;
            }
        }
    }

    int answer = -1;
    for (int a = 1; a <= N; ++a) {
        bool flag = true;
        for (int i = 1; i <= N; ++i) {
            if (!reach[i][a]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            answer = a;
            break;
        }
    }

    cout << answer;


    return 0;
}