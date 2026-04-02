#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> q;
    priority_queue<int> pq;

    for (int i = 0; i < priorities.size(); i++)
    {
        q.push({i, priorities[i]});
        pq.push(priorities[i]);
    }

    int answer = 0;

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        if (cur.second == pq.top())
        {
            pq.pop();
            answer++;

            if (cur.first == location)
                return answer;
        }
        else
        {
            q.push(cur);
        }
    }

    return answer;
}