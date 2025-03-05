#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<string> array;
    for (int i = 0;i < N;i++) {
        
            string row;
            cin >> row;
            array.push_back(row);
        
    }

    for (int i = 0;i < N;i++) {
        for (int j = 0;j < M;j++) {
            cout << array[i][M - j - 1];
        }
        cout << endl;
    }

    return 0;
}