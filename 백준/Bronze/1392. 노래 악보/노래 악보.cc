#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<int> musics;

    for (int i = 1;i <= N;i++) {
        int music_time;
        cin >> music_time;
        for (int j = 0;j < music_time;j++) {
            musics.push_back(i);
        }
    }

    for (int i = 0;i < Q;i++) {
        int q;
        cin >> q;
        cout << musics[q] << endl;
    }
    return 0;
}