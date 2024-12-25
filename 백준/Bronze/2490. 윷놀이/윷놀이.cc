#include <iostream>
using namespace std;

void evaluate(int A, int B, int C, int D) {
    int deung = A + B + C + D; // True 값을 더해줌
    if (deung == 0)
        cout << 'D';
    else if (deung == 1)
        cout << 'C';
    else if (deung == 2)
        cout << 'B';
    else if (deung == 3)
        cout << 'A';
    else
        cout << 'E';
    cout << endl;
}

int main() {
    for (int i = 0; i < 3; ++i) { // 3번 입력받기
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        evaluate(A, B, C, D);
    }
    return 0;
}
