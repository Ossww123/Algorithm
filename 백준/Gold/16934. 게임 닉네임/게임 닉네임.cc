#include <iostream>
#include <string>

using namespace std;

struct TrieNode {
    bool isEnd;
    int count;
    int endCount;
    TrieNode* children[26];
}nodePool[1000050];

int nextFree = 0;

TrieNode* allocateNode() {
    TrieNode* node = &nodePool[nextFree++];
    node->isEnd = false;
    node->count = 0;
    node->endCount = 0;
    for (int i = 0; i < 26; i++) {
        node->children[i] = nullptr;
    }
    return node;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    TrieNode* root = allocateNode();

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string nickname;
        cin >> nickname;

        bool isComplete = false;
        string alias = "";
        TrieNode* curr = root;

        for (char c : nickname) {
            int index = c - 'a';
            alias += c;

            if (!curr->children[index]) {
                curr->children[index] = allocateNode();
            }

            curr = curr->children[index];
            curr->count++;
            if (!isComplete && curr->count == 1) {
                cout << alias << '\n';
                isComplete = true;
            }
        }
        curr->isEnd = true;
        curr->endCount++;
        if (!isComplete) {
            if (curr->endCount > 1)
                cout << alias << curr->endCount << '\n';
            else
                cout << alias << '\n';
        }
    }

    return 0;
}