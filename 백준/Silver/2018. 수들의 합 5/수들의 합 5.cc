#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int count = 0;
    int left = 1, right = 1;
    int sum = 1;
    
    while (left <= N) {
        if (sum == N) {
            count++;
            sum -= left;
            left++;
        }
        else if (sum < N) {
            right++;
            if (right <= N) {
                sum += right;
            } else {
                break;
            }
        }
        else {
            sum -= left;
            left++;
        }
    }
    
    cout << count;
    
    return 0;
}