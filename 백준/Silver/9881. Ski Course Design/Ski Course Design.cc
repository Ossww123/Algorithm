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

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);

    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    int ans = 0xFFFFFF;

    for (int min_num = 0; min_num <= 100 - 17; ++min_num) {
        int value = 0;
        for (int i = 0; i < n; ++i) {
            if (heights[i] < min_num) {
                value += (heights[i] - min_num) * (heights[i] - min_num);
            }
            else if (heights[i] > min_num + 17) {
                value += (heights[i] - min_num - 17) * (heights[i] - min_num - 17);
            }
        }
        ans = min(value, ans);
    }

    cout << ans;

    return 0;
}