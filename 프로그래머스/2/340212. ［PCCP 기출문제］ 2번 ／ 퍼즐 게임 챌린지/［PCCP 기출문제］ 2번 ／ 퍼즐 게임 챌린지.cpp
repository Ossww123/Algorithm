#include <string>
#include <vector>

using namespace std;

bool solvePuzzle(vector<int> diffs, vector<int> times, long long limit, int level){
    long long totalTime = 0;
    int n = diffs.size();
    for (int i=0;i<n;i++){
        int diffLevel = max(0, diffs[i]-level);
        int time = 0;
        if (i > 0){
            time = times[i] + (times[i]+times[i-1]) * diffLevel;
        }
        else{
            time = times[i];
        }
        totalTime += time;
        
        if (totalTime > limit) return false;
    }
    
    return true;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    
    int left = 1;
    int right = 100000;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (solvePuzzle(diffs, times, limit, mid)) {
            answer = mid;
            right = mid-1;
        } else {
            left = mid + 1;
        }
    }
    
    return answer;
}