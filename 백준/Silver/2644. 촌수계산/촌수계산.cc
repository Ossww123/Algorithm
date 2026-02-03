#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int a, b;
    cin >> a >> b;
    
    int k;
    cin >> k;

    vector<vector<int>> edges(n + 1);

    for (int i = 0; i < k; i++)
    {
        int q, w;
        cin >> q >> w;
        edges[q].push_back(w);
        edges[w].push_back(q);
    }
    
    vector<int> dist(n + 1, -1);
    dist[a] = 0;

    queue<int> bfsQ;
    bfsQ.push(a);
    
    while (!bfsQ.empty())
    {
        int s = bfsQ.front();
        bfsQ.pop();

        for (int t : edges[s])
        {
            if (dist[t] != -1) continue;
            
            dist[t] = dist[s] + 1;
            bfsQ.push(t);
        }
    }
    
    cout << dist[b];
    
    return 0;
}
