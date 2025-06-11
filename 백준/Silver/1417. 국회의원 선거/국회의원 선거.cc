#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int DY[4] = { -1,0,1,0 }; // 북, 동, 남, 서 방향
int DX[4] = { 0,1,0,-1 };


int main() {
    int N;
    cin >> N;

    int dasom;
    cin >> dasom;

    priority_queue<int> others;

    for (int i = 1; i < N; i++) {
        int votes;
        cin >> votes;
        others.push(votes);
    }

    int ans = 0;

    while (!others.empty() && others.top() >= dasom) {
        int max_votes = others.top();
        others.pop();

        max_votes--;
        dasom++;
        ans++;

        if (max_votes > 0) {
            others.push(max_votes);
        }
    }

    cout << ans;

    return 0;
}