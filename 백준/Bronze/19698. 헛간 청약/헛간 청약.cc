#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, W, H, L;
    cin >> N >> W >> H >> L;

    int w = W / L;
    int h = H / L;

    int ans = min(N, w * h);

    cout << ans;

    return 0;
}
