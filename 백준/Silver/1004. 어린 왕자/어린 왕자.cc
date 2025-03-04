#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int N;
        cin >> N;

        vector<bool> start_point(N);
        vector<bool> end_point(N);

        for (int i = 0;i < N;i++) {
            int px, py, r;
            cin >> px >> py >> r;

            float start_to_point = sqrt((x1 - px)*(x1-px) + (y1-py)*(y1-py));
            float end_to_point = sqrt((x2 - px) * (x2 - px) + (y2 - py) * (y2 - py));

            start_point[i] = r > start_to_point;
            end_point[i] = r > end_to_point;
        }

        int cnt = 0;
        for (int i = 0;i < N;i++) {
            if (start_point[i] != end_point[i]) {
                cnt++;
            }
        }

        cout << cnt << endl;
    }


    return 0;
}