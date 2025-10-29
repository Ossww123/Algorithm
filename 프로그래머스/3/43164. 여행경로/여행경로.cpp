#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;


vector<string> solution(vector<vector<string>> tickets) {
    
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
    
    for (auto &t : tickets) {
        const string &from = t[0];
        const string &to   = t[1];
        graph[from].push(to);
    }
    
    stack<string> stk;
    vector<string> answer;
    
    stk.push("ICN");
    
    while (!stk.empty()) {
        string curr = stk.top();
        
        if (!graph[curr].empty()) {
            string next = graph[curr].top();
            graph[curr].pop();
            stk.push(next);
        }
        else {
            answer.push_back(curr);
            stk.pop();
        }
    }
    
    reverse(answer.begin(), answer.end());
    return answer;
}
