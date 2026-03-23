#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    int n = discount.size();
    int m = want.size();
    int idx = 0;
    
    while(true)
    {
        if (idx + 10 > n) break;
        
        bool isInclude = true;
        for(int i = idx; i < idx + 10; i++)
        {
            string dcnt = discount[i];
            
            if (find(want.begin(), want.end(), dcnt) == want.end())
            {
                idx = i + 1;
                isInclude = false;
                break;
            }
        }
        if (!isInclude) continue;
        
        unordered_map<string, int> wants;
        for(int i = 0; i < m; i++)
        {
            wants[want[i]] = number[i];
        }
        
        bool isNumMatch = true;
        for(int i = idx; i < idx + 10; i++)
        {
            string dcnt = discount[i];
            
            if (wants[dcnt] > 0)
            {
                wants[dcnt] -= 1;
            }
            else
            {
                idx++;
                isNumMatch = false;
                break;
            }
        }
        if(!isNumMatch) continue;
        
        answer++;
        idx++;
    }
    
    return answer;
}