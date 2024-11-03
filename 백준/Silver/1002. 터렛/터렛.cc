#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        
        long long distance = (long long)(x1 - x2) * (x1 - x2) + 
                           (long long)(y1 - y2) * (y1 - y2);
        long long add_r = (long long)(r1 + r2) * (r1 + r2);
        long long sub_r = (long long)(r1 - r2) * (r1 - r2);
        
        if (x1 == x2 && y1 == y2) {
            if (r1 == r2) 
                cout << -1 << endl;  // 두 원이 완전히 일치
            else 
                cout << 0 << endl;   // 중심은 같지만 반지름이 다름
        }
        else if (distance > add_r)   // 두 원이 떨어져 있음
            cout << 0 << endl;
        else if (distance < sub_r)   // 한 원이 다른 원 안에 있음
            cout << 0 << endl;
        else if (distance == add_r)  // 외접
            cout << 1 << endl;
        else if (distance == sub_r)  // 내접
            cout << 1 << endl;
        else                        // 두 점에서 만남
            cout << 2 << endl;
    }
    return 0;
}