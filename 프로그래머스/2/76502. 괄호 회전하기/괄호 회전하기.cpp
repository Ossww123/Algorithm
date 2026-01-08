#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isValid(string s)
{
    stack<char> stk;

    for (char c : s)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            stk.push(c);
        }
        else
        {
            if (stk.empty()) return false;

            char top = stk.top();
            stk.pop();

            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '['))
            {
                return false;
            }
        }
    }

    return stk.empty();
}

int solution(string s)
{
    int n = s.size();
    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        if (isValid(s))
            answer++;

        s = s.substr(1) + s[0];
    }

    return answer;
}
