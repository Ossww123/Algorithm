#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int n = progresses.size();
    vector<int> temp1(n, 100);
    for(int i=0; i<n; i++)
    {
        temp1[i] = temp1[i] - progresses[i];
    }
    
    vector<int> temp2(n, 0);
    for(int i=0; i<n; i++)
    {
        temp2[i] = temp1[i] % speeds[i] == 0 ? temp1[i] / speeds[i] : temp1[i] / speeds[i] + 1;
    }
    
    vector<int> answer;
    
    int cnt = 0;
    int maxValue = temp2[0];
    for(int i =0; i<n; i++)
    {
        // cout << temp2[i] << ' ' << maxValue << endl;
        if (temp2[i] <= maxValue)
        {
            cnt++;
        }
        else
        {
            maxValue = temp2[i];
            answer.push_back(cnt);
            cnt = 1;
        }
        if (i == n-1) answer.push_back(cnt);
    }
    
    return answer;
}