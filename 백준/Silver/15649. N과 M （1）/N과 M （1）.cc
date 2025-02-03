#include <iostream>
#include <vector>

using namespace std;

vector<int> nums;
vector<bool> visited(9, false);

void backtracking(int N, int M,int idx = 0) {
    if (idx == M) {
        for (int i = 0; i < M; i++) {
            cout << nums[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (visited[i]) continue;
        nums.push_back(i);
        visited[i] = true;
        backtracking(N, M, idx + 1);
        visited[i] = false;
        nums.pop_back();
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