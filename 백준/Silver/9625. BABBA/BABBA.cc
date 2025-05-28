#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int DY[4] = { -1,0,1,0 }; // 북, 동, 남, 서 방향
int DX[4] = { 0,1,0,-1 };


int main() {
    
    int n;
    cin >> n;

    vector<pair<int, int>> DP(50, {0, 0});

    DP[0] = { 1, 0 };
    for (int i = 1; i <= 45; i++) {
        DP[i].first = DP[i - 1].second;
        DP[i].second = DP[i - 1].first + DP[i - 1].second;
    }

    cout << DP[n].first << ' ' << DP[n].second;

    return 0;
}