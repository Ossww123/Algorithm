#include <iostream>
#include <vector>

using namespace std;

struct max_score {
    // 이전 칸을 밟았는 지에 따른 구분
    int cont_score;
    int disc_score;
};

int main() {
    int N;
    cin >> N;

    vector<int> scores(N+1);
    for (int i = 1; i < N + 1; i++) {
        cin >> scores[i];
    }

    vector<max_score> DP(N+1);
    DP[0] = { 0, 0 };
    DP[1] = { scores[1], scores[1] };

    if (N >= 2) {
        for (int i = 2; i < N + 1; i++) {
            DP[i].cont_score = DP[i - 1].disc_score + scores[i];
            DP[i].disc_score = max(DP[i - 2].cont_score, DP[i - 2].disc_score) + scores[i];
        }
    }

    cout << max(DP[N].cont_score, DP[N].disc_score);

    return 0;
}
