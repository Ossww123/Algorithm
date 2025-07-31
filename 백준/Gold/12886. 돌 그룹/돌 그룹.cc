#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct State {
    int a, b, c;
    
    State(int a, int b, int c) : a(a), b(b), c(c) {
        // 항상 정렬된 상태로 유지하여 중복 제거
        vector<int> v = {a, b, c};
        sort(v.begin(), v.end());
        this->a = v[0];
        this->b = v[1]; 
        this->c = v[2];
    }
    
    bool operator<(const State& other) const {
        if (a != other.a) return a < other.a;
        if (b != other.b) return b < other.b;
        return c < other.c;
    }
    
    bool isTarget(int target) const {
        return a == target && b == target && c == target;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int A, B, C;
    cin >> A >> B >> C;
    
    int total = A + B + C;
    
    // 총합이 3으로 나누어떨어지지 않으면 불가능
    if (total % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }
    
    int target = total / 3;
    State start(A, B, C);
    
    // 이미 목표 상태라면
    if (start.isTarget(target)) {
        cout << 1 << endl;
        return 0;
    }
    
    // BFS로 목표 상태에 도달 가능한지 확인
    set<State> visited;
    queue<State> q;
    
    q.push(start);
    visited.insert(start);
    
    while (!q.empty()) {
        State current = q.front();
        q.pop();
        
        // 현재 상태에서 가능한 모든 연산 시도
        vector<int> stones = {current.a, current.b, current.c};
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j || stones[i] == stones[j]) continue;
                
                // stones[i]가 더 작고 stones[j]가 더 큰 경우
                if (stones[i] < stones[j]) {
                    vector<int> newStones = stones;
                    newStones[j] -= newStones[i];  // 큰 쪽에서 작은 쪽만큼 빼기
                    newStones[i] *= 2;             // 작은 쪽을 2배로
                    
                    State newState(newStones[0], newStones[1], newStones[2]);
                    
                    // 목표 상태에 도달했는지 확인
                    if (newState.isTarget(target)) {
                        cout << 1 << endl;
                        return 0;
                    }
                    
                    // 아직 방문하지 않은 상태라면 큐에 추가
                    if (visited.find(newState) == visited.end()) {
                        visited.insert(newState);
                        q.push(newState);
                    }
                }
            }
        }
    }
    
    // 목표 상태에 도달할 수 없음
    cout << 0 << endl;
    return 0;
}