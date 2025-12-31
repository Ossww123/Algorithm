#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    sort(A.begin(), A.end(), [](const auto& x, const auto& y) {
        return x > y;
    });
    
    sort(B.begin(), B.end(), [](const auto& x, const auto& y) {
        return x < y;
    });
    
    int answer = 0;

    int n = A.size();
    for(int i=0; i<n ; i++)
    {
        answer += (A[i] * B[i]);
    }
    
    return answer;
}