#include <iostream>

using namespace std;
typedef long long ll;

ll tree[4000050];
ll arr[1000050];

ll init(int node, int start, int end) {
    if (start == end)
        return tree[node] = arr[start];

    int mid = (start + end) / 2;

    return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

void update(int node, int start, int end, int idx, ll diff) {
    if (idx < start || idx > end) return;

    tree[node] += diff;

    if (start != end) {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, idx, diff);
        update(node * 2 + 1, mid + 1, end, idx, diff);
    }
}

ll sum(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        ll num;
        cin >> num;
        arr[i] = num;
    }

    init(1, 1, N);

    for (int i = 0; i < M + K; i++) {
        ll a, b, c;
        cin >> a >> b >> c;

        // 값 변경
        if (a == 1) {
            ll diff = c - arr[b];
            arr[b] = c;
            update(1, 1, N, b, diff);
        }

        // 구간 합 구하기
        else {
            ll ret = sum(1, 1, N, b, c);
            cout << ret << '\n';
        }
    }
    
    return 0;
}