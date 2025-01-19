#include <iostream>
#include <string>

using namespace std;

struct TrieNode {
    bool isEnd; // 문자열의 끝인지
    TrieNode* children[26]; // 알파벳 소문자 26개

    // 생성자
    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

void insert(TrieNode* root, string str) {
    TrieNode* current = root;
    for (char ch : str) {
        int index = ch - 'a';
        if (current->children[index] == nullptr) {
            current->children[index] = new TrieNode();
        }
        current = current->children[index];
    }
    current->isEnd = true;
}

bool startsWith(TrieNode* root, string prefix) {
    TrieNode* current = root;
    for (char ch : prefix) {
        int index = ch - 'a';
        if (current->children[index] == nullptr) return false;
        current = current->children[index];
    }
    return true;
}

void deleteTrie(TrieNode* node) {
    for (int i = 0; i < 26; i++) {
        if (node->children[i]) {
            deleteTrie(node->children[i]);
        }
    }
    delete node;
}

int main() {
    int N, M;
    cin >> N >> M;

    TrieNode* root = new TrieNode;

    string str;
    for (int i = 0; i < N; i++) {
        cin >> str;
        insert(root, str);
    }

    int cnt = 0;
    for (int i = 0; i < M; i++) {
        cin >> str;
        if (startsWith(root, str)) {
            cnt++;
        }
    }

    cout << cnt << '\n';

    deleteTrie(root);

    return 0;
}
