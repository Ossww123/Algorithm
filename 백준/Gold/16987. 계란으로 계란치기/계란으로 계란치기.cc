#include <iostream>
#include <vector>

using namespace std;

struct egg {
    int dur;
    int wei;
};

vector<egg> eggs;
int max_crash = 0;

void backtracking(int N, int cur = 0, int cnt = 0) {
    if (cur == N) {
        if (cnt > max_crash)
            max_crash = cnt;
        return;
    }

    if (eggs[cur].dur <= 0 || cnt == N-1) {
        backtracking(N, cur + 1, cnt);
    }
    else {
        for (int i = 0; i < N; i++) {
            if (cur == i) continue;
            if (eggs[i].dur <= 0) continue;
            eggs[cur].dur -= eggs[i].wei;
            eggs[i].dur -= eggs[cur].wei;
            if (eggs[cur].dur <= 0) cnt++;
            if (eggs[i].dur <= 0) cnt++;
            backtracking(N, cur + 1, cnt);
            if (eggs[cur].dur <= 0) cnt--;
            if (eggs[i].dur <= 0) cnt--;
            eggs[cur].dur += eggs[i].wei;
            eggs[i].dur += eggs[cur].wei;
        }
    }
}

int main() {
    int N;
    cin >> N;
   
    for (int i = 0; i < N; i++) {
        int d, w;
        cin >> d >> w;
        eggs.push_back({ d, w });
    }
    
    backtracking(N);

    cout << max_crash;

    return 0;
}
