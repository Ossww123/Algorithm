#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;

int find(int x) {
    if(parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

bool unite(int x, int y) {
    int px = find(x), py = find(y);
    if(px == py) return false;
    parent[px] = py;
    return true;
}

int solution(int n, vector<vector<int>> costs) {
    // Union-Find 초기화
    parent.resize(n);
    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }
    
    // 비용 기준 정렬
    sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    });
    
    int answer = 0;
    int edgeCount = 0;
    
    for(auto& cost : costs) {
        if(unite(cost[0], cost[1])) {
            answer += cost[2];
            edgeCount++;
            if(edgeCount == n - 1) break;
        }
    }
    
    return answer;
}