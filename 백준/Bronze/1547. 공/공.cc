#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int ball_pos = 1;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        if (a == ball_pos) {
            ball_pos = b;
        }
        else if (b == ball_pos) {
            ball_pos = a;
        }
    }

    cout << ball_pos;
}
