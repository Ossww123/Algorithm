#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<vector<int>> edges)
{
    int MAX_NUM = 1000001;
    
    vector<int> incoming(MAX_NUM, 0);
    vector<int> outgoing(MAX_NUM, 0);
    vector<bool> existed(MAX_NUM, false);
    
    for(auto edge : edges)
    {
        int v = edge[0];
        int w = edge[1];
        
        incoming[w]++;
        outgoing[v]++;
        existed[v] = true;
        existed[w] = true;
    }
    
    int extra_node = -1;
    int component_sum = -1;
    for(int i=1;i<MAX_NUM;i++)
    {
        if (incoming[i] == 0 && outgoing[i] >= 2)
        {
            extra_node = i;
            existed[extra_node] = false;
            component_sum = outgoing[extra_node];
            break;
        }
    }
    
    for(auto edge : edges)
    {
        int v = edge[0];
        int w = edge[1];
        if (v == extra_node ) incoming[w]--;
    }
    
    vector<int> answer = {extra_node, 0, 0, 0};
    for(int i=1;i<MAX_NUM;i++)
    {
        if (incoming[i] == 0 && existed[i]) answer[2]++;
        if (incoming[i] == outgoing[i] && incoming[i] >= 2) answer[3]++;
    }
    answer[1] = component_sum - answer[2] - answer[3];
    
    return answer;
}