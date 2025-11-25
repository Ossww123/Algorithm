#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    int length = right - left + 1;
    
    vector<int> answer(length,0);
    
    for (int i=0; i<length;i++){
        answer[i] = max(left / n, left % n) + 1;
        left++;
    }
    
    return answer;
}