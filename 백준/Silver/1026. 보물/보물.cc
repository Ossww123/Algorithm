#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A;
    vector<int> B;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A.push_back(a);
    }

    for (int i = 0; i < N; i++) {
        int b;
        cin >> b;
        B.push_back(b);
    }

    sort(A.begin(), A.end());

    sort(B.begin(), B.end(), greater<int>());

    int result = 0;

    for (int i = 0; i < N; i++) {
        result += A[i] * B[i];
    }

    cout << result;

    return 0;
}
