#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> num(10, 0);

    string N;
    cin >> N;

    for (char c : N) {
        int index = c - '0';
        num[index]++;
    }

    int temp = (num[6] + num[9] + 1) / 2;
    num[6] = num[9] = temp;

    int max_cnt = 0;
    for (int i = 0;i < 10;++i) {
        if (num[i] > max_cnt) max_cnt = num[i];
    }

    cout << max_cnt;

    return 0;
}