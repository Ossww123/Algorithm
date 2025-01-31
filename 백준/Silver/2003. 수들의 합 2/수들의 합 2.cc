#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    int s = 0, e = 0;
    long long sum = 0;
    int cnt = 0;

    while (s < N) {
        if (sum < M && e < N) {
            sum += nums[e++];
        }
        else {
            if (sum == M) {
                cnt++;
            }
            sum -= nums[s++];
        }
    }

    cout << cnt;
    return 0;
}