#include <string>
#include <vector>
#include <queue>

using namespace std;

bool canMove(string a, string b) {
    int diffCount = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            diffCount++;
        }
    }
    return diffCount == 1;
}

int solution(string begin, string target, vector<string> words) {
    int n = words.size();
    
    queue<pair<string, int>> q;
    vector<bool> visited(n, false);
    
    q.push({begin, 0});
    
    while (!q.empty()) {
        string current = q.front().first;
        int dist = q.front().second;
        q.pop();
        
        if (current == target) {
            return dist;
        }
        
        for (int i = 0; i < n; i++) {
            if (!visited[i] && canMove(current, words[i])) {
                visited[i] = true;
                q.push({words[i], dist + 1});
            }
        }
    }
    
    return 0;
}