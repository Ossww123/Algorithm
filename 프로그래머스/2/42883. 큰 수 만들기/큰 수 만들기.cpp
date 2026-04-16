#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    int l = number.length();
    int n = l - k;
    
    string answer = "";
    int startIdx = 0;
    for (int i=0; i<n; i++)
    {
        int currNum = -1;
        char c = ' ';
        for(int j=startIdx; j < k + i + 1; j++)
        {
            if(number[j] - '0' > currNum)
            {
                currNum = number[j] - '0';
                c = number[j];
                startIdx = j+1;
            }
        }
        answer += c;
        
        // cout << startIdx;
    }
    
    return answer;
}