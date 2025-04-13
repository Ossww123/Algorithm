#include <iostream>
#include <vector>

using namespace std;

void hanoi(int n, int start, int end, vector<pair<int, int>>& moves) {
    if (n == 0) return;
    
    int other = 6 - start - end; // 나머지 기둥
    
    hanoi(n-1, start, other, moves);
    moves.push_back({start, end});
    hanoi(n-1, other, end, moves);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    
    vector<pair<int, int>> moves;
    hanoi(N, 1, 3, moves);
    
    cout << moves.size() << "\n";
    for (const auto& move : moves) {
        cout << move.first << " " << move.second << "\n";
    }
    
    return 0;
}