#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

vector<ll> tree;
vector<ll> arr;

// 세그먼트 트리 초기 구축
ll init(int node, int start, int end) {
    if (start == end)
        return tree[node] = arr[start];

    int mid = (start + end) / 2;
    return tree[node] = init(node * 2, start, mid) +
        init(node * 2 + 1, mid + 1, end);
}

// 값 업데이트
void update(int node, int start, int end, int idx, ll diff) {
    if (idx < start || idx > end) return;

    tree[node] += diff;

    if (start != end) {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, idx, diff);
        update(node * 2 + 1, mid + 1, end, idx, diff);
    }
}

// 구간 합 쿼리
ll sum(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) +
        sum(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    arr.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // 트리 크기를 충분히 크게 설정 (약 4*n)
    tree.resize(4 * N);
    init(1, 0, N - 1);

    for (int i = 0; i < M + K; i++) {
        ll a, b, c;
        cin >> a >> b >> c;

        if (a == 1) {  // 업데이트 쿼리
            ll diff = c - arr[b - 1];
            arr[b - 1] = c;
            update(1, 0, N - 1, b - 1, diff);
        }
        else {  // 구간 합 쿼리
            cout << sum(1, 0, N - 1, b - 1, c - 1) << '\n';
        }
    }

    return 0;
}