#include <string>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>

using namespace std;

bool isSame(const string& user_id, const string& banned_id){
    if (user_id.length() != banned_id.length()) return false;
    
    for (int i=0;i<user_id.length();i++){
        if (banned_id[i] != '*' && banned_id[i] != user_id[i]){
            return false;
        }
    }
    
    return true;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int n = user_id.size();
    int m = banned_id.size();
    
    vector<vector<int>> match_idx(m);
    for(int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            if(isSame(user_id[j], banned_id[i])){
                match_idx[i].push_back(j);
            }
        }
    }
    
    set<vector<int>> result;
    
    struct State {
        int banned_idx;
        vector<bool> visited;
        vector<int> selected;
    };
    
    stack<State> stk;
    
    State init;
    init.banned_idx = 0;
    init.visited = vector<bool>(n, false);
    init.selected = vector<int>();
    stk.push(init);
    
    while (!stk.empty()) {
        State curr = stk.top();
        stk.pop();
        
        if (curr.banned_idx == m) {
            vector<int> temp = curr.selected;
            sort(temp.begin(), temp.end());
            result.insert(temp);
            continue;
        }
        
        for (int user_idx : match_idx[curr.banned_idx]) {
            if (!curr.visited[user_idx]) {
                State next;
                next.banned_idx = curr.banned_idx + 1;
                next.visited = curr.visited;
                next.visited[user_idx] = true;
                next.selected = curr.selected;
                next.selected.push_back(user_idx);
                
                stk.push(next);
            }
        }
    }
    
    return result.size();
}