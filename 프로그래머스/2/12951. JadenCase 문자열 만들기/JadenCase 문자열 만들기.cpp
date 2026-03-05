#include <string>
#include <vector>
#include <sstream>

using namespace std;

bool isUpperAlpha(char c)
{
    return 'A' <= c && c <= 'Z';
}

bool isLowerAlpha(char c)
{
    return 'a' <= c && c <= 'z';
}

string solution(string s) {
    string answer = "";
    
    bool isStart = true;
    for (char c : s)
    {
        if (c == ' ')
        {
            answer += c;
            isStart = true;
            continue;
        }

        char nc = c;
        if (isStart && isLowerAlpha(nc))
        {
            nc = nc - 'a' + 'A';
        }
        else if (!isStart && isUpperAlpha(nc))
        {
            nc = nc - 'A' + 'a';
        }
        answer += nc;
        
        isStart = false;
    }
    
    return answer;
}