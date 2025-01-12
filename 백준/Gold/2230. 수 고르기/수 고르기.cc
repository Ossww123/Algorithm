#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> nums;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());

    int L = 0, R = 0;
    int min_diff = INT_MAX;

    while (R < N) {
        int diff = nums[R] - nums[L];

        if (diff >= M && L < R) {
            min_diff = min(min_diff, diff);
            L++;
        }
        else {
            R++;
        }
    }

    cout << min_diff;

    return 0;
}
