#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int p[1000010]; // 부모 노드 저장 배열

// 루트 노드 찾기 (경로 압축 적용)
int find(int n) {
    if (p[n] == n) return n;  // 자신이 루트일 경우 그대로 반환
    return p[n] = find(p[n]); // 경로 압축: 부모를 루트로 갱신
}

// 두 집합 합치기
void merge(int a, int b) {
    a = find(a); // a의 루트 찾기
    b = find(b); // b의 루트 찾기
    if (a != b) p[b] = a; // 루트가 다르면 b의 부모를 a로 설정
}

int main() {
    ios::sync_with_stdio(false); // 입출력 최적화
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // 부모 배열 초기화
    for (int i = 0; i <= n; i++) {
        p[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int cal, a, b;
        cin >> cal >> a >> b;

        if (cal == 0) {
            // 집합 합치기
            merge(a, b);
        }
        else {
            // 연결 여부 확인
            if (find(a) == find(b)) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}
