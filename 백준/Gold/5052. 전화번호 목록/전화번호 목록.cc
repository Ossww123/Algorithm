#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int GO_MAX = 10;    // 트라이 노드마다 포인터 개수
const int MAX_T = 50;     // 최대 테스트케이스
const int MAX_N = 10000;  // 각 테스트케이스당 최대 문자열 수
const int MAX_LEN = 10;   // 각 문자열의 최대 길이
const int POOL_SIZE = MAX_N * MAX_LEN + 1;

struct Trie {
    int go[GO_MAX];
    bool output;
    bool goexist;
};

Trie nodes[POOL_SIZE];
int unused;

// 새로운 노드 초기화
void init_node(int node_idx) {
    fill(nodes[node_idx].go, nodes[node_idx].go + GO_MAX, -1);
    nodes[node_idx].output = nodes[node_idx].goexist = false;
}

// 트라이 초기화 (테스트케이스마다 호출)
void init_trie() {
    unused = 0;
    init_node(unused++);  // 루트 노드 생성
}

// 문자열 삽입
void insert(const string& str, int node = 0, int idx = 0) {
    if (idx == str.length()) {
        nodes[node].output = true;
        return;
    }
    
    int& next = nodes[node].go[str[idx] - '0'];
    if (next == -1) {
        next = unused;
        init_node(unused++);
    }
    nodes[node].goexist = true;
    insert(str, next, idx + 1);
}

// 일관성 검사
bool consistent(int node) {
    if (nodes[node].goexist && nodes[node].output) return false;
    
    for (int i = 0; i < GO_MAX; i++) {
        if (nodes[node].go[i] != -1 && !consistent(nodes[node].go[i])) 
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        
        init_trie();
        
        for (int i = 0; i < N; i++) {
            string tel;
            cin >> tel;
            insert(tel);
        }
        
        cout << (consistent(0) ? "YES\n" : "NO\n");
    }

    return 0;
}