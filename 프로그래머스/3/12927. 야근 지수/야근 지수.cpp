#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    priority_queue<int> pq;
    
    for(int work : works) {
        pq.push(work);
    }
    
    for(int i = 0; i < n; i++) {
        if(pq.empty()) break;
        
        int maxWork = pq.top();
        pq.pop();
        
        if(maxWork > 0) {
            pq.push(maxWork - 1);
        }
    }
    
    long long answer = 0;
    while(!pq.empty()) {
        int work = pq.top();
        pq.pop();
        answer += (long long)work * work;
    }
    
    return answer;
}