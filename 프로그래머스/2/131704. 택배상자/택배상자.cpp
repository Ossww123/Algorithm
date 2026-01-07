#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> order)
{
    int n = (int)order.size();
    stack<int> st;
    int curr = 1;
    int cnt = 0;

    for (int target : order)
    {
        while (curr <= n && curr < target)
        {
            st.push(curr);
            curr++;
        }

        
        if (curr <= n && curr == target)
        {
            cnt++;
            curr++;
        }
        
        else if (!st.empty() && st.top() == target)
        {
            st.pop();
            cnt++;
        }
        
        else
        {
            break;
        }
    }

    return cnt;
}
