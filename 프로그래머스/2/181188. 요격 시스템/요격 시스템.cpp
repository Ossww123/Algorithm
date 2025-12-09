#include <string>
#include <vector>
#include <algorithm> // sort 사용하려면 필요!

using namespace std;

int solution(vector<vector<int>> targets)
{
    sort(targets.begin(), targets.end(),
         [](const vector<int>& a, const vector<int>& b) {
             if (a[1] == b[1]) return a[0] < b[0];
             else              return a[1] < b[1];
         });

    int answer = 0;
    int curr = -1;
    for (auto target:targets)
    {
        if(target[0] > curr)
        {
            answer++;
            curr = target[1] - 1;
        }
    }
    
    return answer;
}
