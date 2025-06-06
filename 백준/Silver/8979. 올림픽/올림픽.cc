#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct nation {
    int num;
    int gold;
    int silver;
    int bronze;
};

bool compare(const nation& a, const nation& b) {
    if (a.gold != b.gold) return a.gold > b.gold;
    if (a.silver != b.silver) return a.silver > b.silver;
    return a.bronze > b.bronze;
}

int main() {
    
    int N, K;
    cin >> N >> K;
    
    vector<nation> nations(N);
    for (int i = 0; i < N; i++) {
        cin >> nations[i].num >> nations[i].gold >> nations[i].silver >> nations[i].bronze;
    }

    sort(nations.begin(), nations.end(), compare);

    int rank = 1;
    for (int i = 0; i < N; i++) {
        if (i > 0 && (nations[i].gold != nations[i - 1].gold ||
            nations[i].silver != nations[i - 1].silver ||
            nations[i].bronze != nations[i - 1].bronze)) {
            rank = i + 1;
        }

        if (nations[i].num == K) {
            cout << rank << endl;
            break;
        }
    }

    return 0;
}