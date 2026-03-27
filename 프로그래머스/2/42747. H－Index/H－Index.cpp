#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), [](int a, int b){
        return a > b;
    });
    
    int n = citations.size();
    int answer = 0;
    
    for (int i = 0; i < n; i++)
    {
        int temp = i + 1;
        if (citations[i] >= temp) answer = temp;
    }
    
    return answer;
}