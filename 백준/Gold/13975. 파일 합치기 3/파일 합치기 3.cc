#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int K;
        cin >> K;

        priority_queue<long, vector<long>, greater<long>> min_heap;
        for (int i = 0;i < K;i++) {
            int file_size;
            cin >> file_size;
            min_heap.push(file_size);
        }

        long result = 0;
        while (--K) {
            long A, B;
            A = min_heap.top();
            min_heap.pop();
            B = min_heap.top();
            min_heap.pop();
            
            result += (A + B);
            min_heap.push(A + B);
        }
        
        cout << result << endl;
    }
    return 0;
}