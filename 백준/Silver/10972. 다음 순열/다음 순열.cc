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

int ans;

int main()
{
    cin >> N;
    vector<int> permu(N);
    for (int i = 0; i < N; ++i) {
        cin >> permu[i];
    }

    if (N == 1) {
        cout << -1;
        return 0;
    }

    int idx = -1;
    for (int i = N - 2; i >= 0; --i) {
        if (permu[i] < permu[i + 1]) {
            idx = i;
            break;
        }
    }

    // 마지막 순열인 경우
    if (idx == -1) {
        cout << -1;
        return 0;
    }

    int swap_idx = -1;
    for (int i = idx + 1; i < N; ++i) {
        if (permu[i] > permu[idx]) {
            if (swap_idx == -1 || permu[i] < permu[swap_idx]) {
                swap_idx = i;
            }
        }
    }

    int temp = permu[idx];
    permu[idx] = permu[swap_idx];
    permu[swap_idx] = temp;

    sort(permu.begin() + idx + 1, permu.end());

    for (int i = 0; i < N; ++i) {
        cout << permu[i];
        if (i < N - 1) cout << " ";
    }

    return 0;
}