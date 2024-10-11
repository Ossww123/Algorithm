#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<ll, ll>> segments(n);

    for (int i = 0; i < n; ++i) {
        cin >> segments[i].first >> segments[i].second;
    }

    sort(segments.begin(), segments.end());

    ll total_length = 0;
    ll current_start = segments[0].first;
    ll current_end = segments[0].second;

    for (int i = 1; i < n; ++i) {
        if (segments[i].first <= current_end) {
            current_end = max(current_end, segments[i].second);
        }
        else {
            total_length += current_end - current_start;
            current_start = segments[i].first;
            current_end = segments[i].second;
        }
    }

    total_length += current_end - current_start;

    cout << total_length << '\n';

    return 0;
}