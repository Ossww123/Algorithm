#include <iostream>

using namespace std;

bool isHansoo(int num) {

    if (num < 100) {
        return true;
    }

    else if (num < 1000) {
        int h, t, o;
        h = num / 100;
        t = (num % 100) / 10;
        o = num % 10;

        if (h - t == t - o) {
            return true;
        }
        else {
            return false;
        }
    }

    else {  // 1000
        return false;
    }


}

int main()
{
    int N;
    cin >> N;

    int answer = 0;
    for (int i = 1; i <= N; i++) {
        if (isHansoo(i))
            answer++;
    }

    cout << answer;

    return 0;
}
