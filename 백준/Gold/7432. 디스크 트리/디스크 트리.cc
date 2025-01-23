#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct TrieNode {
    string directory;
    map<string, TrieNode*> children;
};

void result(TrieNode* node, int depth = 0) {
    for (const auto& child : node->children) {
        cout << string(depth, ' ') << child.first << '\n';
        result(child.second, depth + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    TrieNode* root = new TrieNode;
    for (int i = 0; i < N; ++i) {
        string line;
        cin >> line;

        TrieNode* curr = root;
        string dir = "";
        for (char c : line) {
            if (c != '\\') {
                dir += c;
            }
            else {
                if (!curr->children.count(dir)) {
                    TrieNode* newNode = new TrieNode;
                    curr->children[dir] = newNode;
                    newNode->directory = dir;
                }
                curr = curr->children[dir];
                dir = "";
            }
        }

        if (!curr->children.count(dir)) {
            TrieNode* newNode = new TrieNode;
            curr->children[dir] = newNode;
            newNode->directory = dir;
        }
    }

    result(root);

    return 0;
}