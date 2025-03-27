#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <functional>

using namespace std;

vector<vector<int>> image;

string solve(int N, int row, int col) {
    if (N == 1) {
        return to_string(image[row][col]);
    }

    string lu = solve(N / 2, row, col);
    string ru = solve(N / 2, row, col + N/2);
    string ld = solve(N / 2, row + N/2, col);
    string rd = solve(N / 2, row+ N/2, col + N/2);

    if (lu.length() == 1 && lu == ru && ru == ld && ld == rd) {
        return lu;
    }
    else {
        return '(' + lu + ru + ld + rd + ')';
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    image.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N;j++) {
            char c = s[j];
            int num = c - '0';
            image[i][j] = num;
        }
    }

    string answer = solve(N, 0, 0);

    cout << answer;

    return 0;
}