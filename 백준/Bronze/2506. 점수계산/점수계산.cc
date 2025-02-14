#include <iostream>

using namespace std;

int nums[100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    int score = 1;
    int result = 0;
    for (int i = 0; i < N; i++) {
        if (nums[i]) {
            result += score++;
        }
        else {
            score = 1;
        }
    }
    
    cout << result;

    return 0;
}