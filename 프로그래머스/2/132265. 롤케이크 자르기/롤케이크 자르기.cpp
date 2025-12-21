#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int solution(vector<int> topping) 
{
    unordered_map<int,int> rightCnt;
    for (int t : topping)
        rightCnt[t]++;

    int rightKinds = rightCnt.size();
    unordered_set<int> leftSet;
    int leftKinds = 0;

    int answer = 0;

    for (int i = 0; i < (int)topping.size() - 1; i++) 
    {
        int x = topping[i];

        if (leftSet.insert(x).second)
            leftKinds++;

        rightCnt[x]--;
        if (rightCnt[x] == 0)
        {
            rightCnt.erase(x);
            rightKinds--;
        }

        if (leftKinds == rightKinds)
            answer++;
    }

    return answer;
}
