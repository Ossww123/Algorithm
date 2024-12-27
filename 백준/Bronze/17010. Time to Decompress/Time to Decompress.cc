#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) { // 3번 입력받기
        int num;
        char cha;
        cin >> num >> cha;

        for (int j = 0; j < num; j++) {
            cout << cha;
        }
        cout << endl;
    }

    return 0;
}
