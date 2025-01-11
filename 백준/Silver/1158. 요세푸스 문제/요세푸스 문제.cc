#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int num;
    Node* nxt;
    Node() {}
    Node(int num) : num(num), nxt(nullptr) {}
};

const int MAX_N = 5001;
Node nodePool[MAX_N];
int poolIdx = 0;

//  새로운 노드를 할당하는 함수
Node* getNewNode(int num) {
    Node* node = &nodePool[poolIdx++];
    node->num = num;
    node->nxt = nullptr;
    return node;
}

int main() {
    int N, K;
    cin >> N >> K;

    // 1 ~ N 까지 원형 연결 리스트 만들기
    Node* head = getNewNode(1);
    Node* cur = head;

    for (int i = 2; i <= N; i++) {
        cur->nxt = getNewNode(i);
        cur = cur->nxt;
    }
    cur->nxt = head; // 마지막 노드와 첫 노드 연결(원형)

    vector<int> result;
    Node* prev = cur;
    cur = head;

    while (result.size() < N) {
        // K-1번 이동
        for (int i = 0; i < K - 1; i++) {
            prev = cur;
            cur = cur->nxt;
        }

        // K번째 노드 제거
        result.push_back(cur->num);
        prev->nxt = cur->nxt;
        cur = cur->nxt;
    }

    cout << '<';
    for (int i = 0; i < N; i++) {
        cout << result[i];
        if (i < N - 1) cout << ", ";
    }

    cout << '>';

    return 0;
}
