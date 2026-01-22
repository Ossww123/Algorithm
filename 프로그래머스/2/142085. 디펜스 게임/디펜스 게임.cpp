#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(int n, int k, vector<int> enemy)
{
    priority_queue<int> pq;
    int round = 0;
    
    for (int e : enemy)
    {
        pq.push(e);
        n -= e;
        
        if (n < 0)
        {
            if (k == 0) break;
            
            n += pq.top();
            pq.pop();
            k--;
        }
        
        round++;
    }
    
    return round;
}