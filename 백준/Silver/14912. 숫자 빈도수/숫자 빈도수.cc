#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int DY[4] = { -1,0,1,0 }; // 북, 동, 남, 서 방향
int DX[4] = { 0,1,0,-1 };


int main() {
    
    int n, d;
    cin >> n >> d;

    int count = 0;

    for (int i = 1; i <= n; i++) {
        int num = i;
        while (num > 0) {
            if (num % 10 == d) {
                count++;
            }
            num /= 10;
        }
    }

    cout << count;

    return 0;
}