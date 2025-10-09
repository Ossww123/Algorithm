#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    if (n > s) return {-1};
    
    vector<int> answer;
    
    int avg = s / n;
    int diff = s - avg * n;
    
    for(int i=0;i<n;i++){
        if (i < (n - diff)){
            answer.push_back(avg);
        }
        else{
            answer.push_back(avg + 1);
        }
    }
    
    return answer;
}