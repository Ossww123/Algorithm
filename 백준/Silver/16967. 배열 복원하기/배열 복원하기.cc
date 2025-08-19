#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>
using std::min;

typedef long long ll;

int main() {
    int h, w, y, x;
    cin >> h >> w >> y >> x;

    vector<vector<int>> matrixB(h+y, vector<int>(w+x));

    for (int r = 0; r < h + y; ++r) {
        for (int c = 0; c < w + x; ++c) {
            cin >> matrixB[r][c];
        }
    }

    if (y >= h || x >= w) {
        for (int r = 0; r < h + y; ++r) {
            for (int c = 0; c < w + x; ++c) {
                cout << matrixB[r][c] << ' ';
            }
            cout << '\n';
        }
    }
    else {
        vector<vector<int>> matrixA(h, vector<int>(w));

        for (int r = 0; r < y; ++r) {
            for (int c = 0; c < w; ++c) {
                matrixA[r][c] = matrixB[r][c];
            }
        }

        for (int r = y; r < h; ++r) {
            for (int c = 0; c < w; ++c) {
                if (c < x) {
                    matrixA[r][c] = matrixB[r][c];
                }
                else {
                    matrixA[r][c] = matrixB[r][c] - matrixA[r-y][c-x];
                }
            }
        }

        for (int r = 0; r < h; ++r) {
            for (int c = 0; c < w; ++c) {
                cout << matrixA[r][c] << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}