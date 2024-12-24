#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {

    int A, B, C, D, E, F, G;

    cin >> A >> B >> C >> D >> E >> F >> G;

    int minNum = 100;
    int sum = 0;

    // A
    if (A % 2 == 1) {
        sum += A;
        if (A < minNum) {
            minNum = A;
        }
    }

    // B
    if (B % 2 == 1) {
        sum += B;
        if (B < minNum) {
            minNum = B;
        }
    }

    // C
    if (C % 2 == 1) {
        sum += C;
        if (C < minNum) {
            minNum = C;
        }
    }

    // D
    if (D % 2 == 1) {
        sum += D;
        if (D < minNum) {
            minNum = D;
        }
    }

    // E
    if (E % 2 == 1) {
        sum += E;
        if (E < minNum) {
            minNum = E;
        }
    }

    // F
    if (F % 2 == 1) {
        sum += F;
        if (F < minNum) {
            minNum = F;
        }
    }

    // G
    if (G % 2 == 1) {
        sum += G;
        if (G < minNum) {
            minNum = G;
        }
    }

    // 결과 출력
    if (sum > 0) {
        cout << sum << endl;
        cout << minNum << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
