#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int indexA = 0, indexB = 0;
    
    while (indexB < B.size()) {
        if (A[indexA] >= B[indexB]) {
            indexB++;
        } else {
            indexA++;
            indexB++;
            answer++;
        }
    }
    
    return answer;
}