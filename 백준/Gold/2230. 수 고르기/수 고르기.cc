#include <iostream>
#include <vector>
#include <algorithm>

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

    int L = 0, R = 0;
    sort(nums.begin(), nums.end());

    int diff, min_diff = -1;
    while (R < N) {
        diff = nums[R] - nums[L];

        if (diff > M) {
            if (min_diff == -1) {
                min_diff = diff;
            }
            else {
                min_diff = min(min_diff, diff);
                L++;
            }
        }
        else if (diff == M) {
            min_diff = diff;
            break;
        }
        else {
            if (R < N) R++;
            else break;
        }
        
    }

    cout << min_diff;

    return 0;
}
