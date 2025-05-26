#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<vector<bool>> isMarked(101, vector<bool>(101, false));

    for (int i = 0; i < 4;i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int x = x1; x < x2;x++) {
            for (int y = y1;y < y2;y++) {
                isMarked[y][x] = true;
            }
        }
    }

    int answer = 0;
    for (int y = 1;y < 100;y++) {
        for (int x = 1;x < 100;x++) {
            if (isMarked[y][x]) answer++;
        }
    }

    cout << answer;
    return 0;
}