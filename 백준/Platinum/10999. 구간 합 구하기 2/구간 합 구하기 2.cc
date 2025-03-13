#include <iostream>
#include <cstring> // memset을 위해 추가

using namespace std;
typedef long long ll;

ll tree[4000050];   // 세그먼트 트리 배열
ll lazy[4000050];   // 지연 업데이트를 위한 배열
ll arr[1000050];    // 원본 배열

// 세그먼트 트리 초기화
ll init(int node, int start, int end) {
    if (start == end)
        return tree[node] = arr[start];

    int mid = (start + end) / 2;
    return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

// 지연된 업데이트 전파
void propagate(int node, int start, int end) {
    // 지연된 업데이트가 있는 경우에만 처리
    if (lazy[node] != 0) {
        // 현재 노드에 지연된 값을 적용 (각 요소에 lazy 값을 더함)
        tree[node] += (end - start + 1) * lazy[node];
        
        // 리프 노드가 아니면 자식 노드에게 지연 업데이트 전달
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        
        // 현재 노드의 지연 업데이트 초기화
        lazy[node] = 0;
    }
}

// 구간 업데이트 - 인덱스 left부터 right까지 값에 value를 더함
void update_range(int node, int start, int end, int left, int right, ll value) {
    // 지연된 업데이트 처리
    propagate(node, start, end);
    
    // 범위를 벗어난 경우
    if (right < start || end < left) return;
    
    // 노드의 범위가 업데이트 범위에 완전히 포함되는 경우
    if (left <= start && end <= right) {
        // 현재 노드의 모든 원소에 value 추가
        tree[node] += (end - start + 1) * value;
        
        // 리프 노드가 아니면 자식 노드들에게 지연 업데이트를 표시
        if (start != end) {
            lazy[node * 2] += value;
            lazy[node * 2 + 1] += value;
        }
        return;
    }
    
    // 부분적으로만 겹치는 경우, 자식 노드로 재귀 호출
    int mid = (start + end) / 2;
    update_range(node * 2, start, mid, left, right, value);
    update_range(node * 2 + 1, mid + 1, end, left, right, value);
    
    // 자식 노드들의 합을 부모 노드에 반영
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

// 구간 합 쿼리
ll sum(int node, int start, int end, int left, int right) {
    // 지연된 업데이트 처리
    propagate(node, start, end);
    
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);            // nullptr 사용하여 약간의 성능 향상
    cout.tie(nullptr);           // 출력 버퍼 비우는 시간 절약
    
    // 배열 초기화
    memset(lazy, 0, sizeof(lazy));

    int N, M, K;
    cin >> N >> M >> K;

    // 입력 최적화
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    init(1, 1, N);

    int total_queries = M + K;
    for (int i = 0; i < total_queries; i++) {
        int a;
        cin >> a;

        if (a == 1) { // 값 변경
            int b, c;
            ll d;
            cin >> b >> c >> d;
            
            // b부터 c까지의 값에 d를 더함
            update_range(1, 1, N, b, c, d);
            
            // 실제 배열 업데이트는 불필요 - 세그먼트 트리로 충분
            // 이 부분을 제거하여 성능 최적화
            // for (int i = b; i <= c; i++) {
            //     arr[i] += d;
            // }
        }
        else { // 구간 합 구하기
            int b, c;
            cin >> b >> c;

            ll ret = sum(1, 1, N, b, c);
            cout << ret << '\n';
        }
    }

    return 0;
}