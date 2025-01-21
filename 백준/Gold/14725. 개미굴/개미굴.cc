#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct TrieNode {
    string str;
    bool isEnd;
    vector<TrieNode*> children;  // 정렬을 위해 vector 사용

    TrieNode() {
        str = "";
        isEnd = false;
    }
};

// 노드 비교를 위한 함수
bool compare(TrieNode* a, TrieNode* b) {
    return a->str < b->str;
}

void answer(TrieNode* node, int depth = 0) {
    // 자식 노드들을 사전순으로 정렬
    sort(node->children.begin(), node->children.end(), compare);

    // 정렬된 순서대로 출력
    for (TrieNode* child : node->children) {
        for (int j = 0; j < depth; j++) {
            cout << "--";
        }
        cout << child->str << '\n';
        if (!child->isEnd) {
            answer(child, depth + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    TrieNode* root = new TrieNode;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        TrieNode* curr = root;
        int K;
        cin >> K;

        for (int j = 0; j < K; j++) {
            string food;
            cin >> food;

            // 현재 층에서 이미 존재하는 먹이인지 확인
            bool found = false;
            TrieNode* next = nullptr;

            for (TrieNode* child : curr->children) {
                if (child->str == food) {
                    found = true;
                    next = child;
                    break;
                }
            }

            // 없는 먹이라면 새 노드 생성
            if (!found) {
                next = new TrieNode;
                next->str = food;
                if (j == K - 1) next->isEnd = true;
                curr->children.push_back(next);
            }

            curr = next;
        }
    }

    answer(root);

    return 0;
}