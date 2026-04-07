#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    stack<pair<int, int>> stk;
    vector<int> answer(n, -1);
    
    for (int i = 0; i<n;i++)
    {
        while(true)
        {
            if (stk.empty() || stk.top().first <= prices[i])
            {
                stk.push({prices[i], i});
                break;
            }
            else
            {
                answer[stk.top().second] = i - stk.top().second;
                stk.pop();
            }
        }
    }
    
    while(!stk.empty())
    {
        answer[stk.top().second] = (n-1) - stk.top().second;
        stk.pop();
    }
    
    return answer;
}