#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine)
{
    sort(tangerine.begin(), tangerine.end());
    
    vector<int> num_kinds;
    
    int cnt = 0;
    int prev = tangerine[0];
    for (int t : tangerine)
    {
        if (t != prev)
        {
            num_kinds.push_back(cnt);
            cnt = 1;
            prev = t;
        }
        else
        {
            cnt++;
        }
    }
    
    num_kinds.push_back(cnt);
    
    sort(num_kinds.begin(), num_kinds.end(),
         [](int x, int y) { return x > y; });
    
    int answer = 0;
    int total = 0;
    for (int n : num_kinds)
    {
        int remained = k - total;
        answer++;
        total += n;
        if (total >= k) break;
    }
    
    return answer;
}