#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;
        vector<int> note1(n);
        for (int i = 0; i < n; ++i) {
            cin >> note1[i];
        }
        sort(note1.begin(), note1.end());

        int m;
        cin >> m;
        vector<int> note2(m);
        for (int i = 0; i < m; ++i) {
            cin >> note2[i];
        }

        for (int i = 0; i < m; ++i) {
            int target = note2[i];
            int left = 0, right = n - 1;
            bool found = false;

            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (note1[mid] == target) {
                    found = true;
                    break;
                }
                else if (note1[mid] < target) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }

            cout << (found ? 1 : 0) << "\n";
        }
    }
    


    return 0;
}