#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> picture(101, vector<int>(101, 0));

    for (int i = 0;i < N;i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int y = y1;y <= y2;y++) {
            for (int x = x1;x <= x2;x++) {
                picture[y][x] += 1;
            }
        }
    }

    int cnt = 0;
    for (int y = 1;y <= 100;y++) {
        for (int x = 1;x <= 100;x++) {
            if (picture[y][x] > M) cnt++;
        }
    }

    cout << cnt;
    return 0;
}