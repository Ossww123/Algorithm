#include <iostream>
#include <vector>

using namespace std;

vector<int> nums(8, 0);

void backtracking(int N, int M, int last=0, int depth=0) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << nums[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (i < last) continue;
        nums[depth] = i;
        backtracking(N, M, i, depth + 1);
        nums[depth] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    backtracking(N, M);

    return 0;
}