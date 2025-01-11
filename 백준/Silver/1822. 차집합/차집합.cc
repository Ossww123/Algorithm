#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int nA, nB;
    cin >> nA >> nB;

    vector<int> A;
    vector<int> B;

    while (nA--) {
        int num;
        cin >> num;
        A.emplace_back(num);
    }
    while (nB--) {
        int num;
        cin >> num;
        B.emplace_back(num);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<int> res;

    for (int a : A) {
        int L = 0;
        int R = B.size();
        bool ainb = false;

        while (L < R) {
            int mid = (L + R) / 2;

            if (a > B[mid]) {
                L = mid + 1;
            }
            else if (a < B[mid]) {
                R = mid;
            }
            else {
                ainb = true;
                break;
            }
        }

        if (!ainb) {
            res.emplace_back(a);
        }

    }
    
    cout << res.size();
    if (res.size()) {
        cout << "\n";
        for (int r : res) {
            cout << r << ' ';
        }
    }

    return 0;
}
