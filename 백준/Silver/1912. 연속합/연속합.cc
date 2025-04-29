#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    int maxValue = nums[0];
    int currMaxValue = nums[0];

    for (int i = 1; i < N; i++) {
        currMaxValue = max(nums[i], currMaxValue + nums[i]);
        maxValue = max(maxValue, currMaxValue);
    }

    cout << maxValue << endl;

    return 0;
}