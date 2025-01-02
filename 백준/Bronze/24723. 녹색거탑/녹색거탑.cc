#include <iostream>
#include <vector>

using namespace std;


int main() {
    int N;
    cin >> N;

    int answer = 1;
    for (int i = 0; i < N; i++) {
        answer *= 2;
    }

    cout << answer;
    return 0;
}
