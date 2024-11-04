#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> stk;
    
    for (char ch : s){
        if (ch == ')'){
            if (stk.empty() || stk.top() == ')'){
                answer = false;
                break;
            }else{
                stk.pop();
            }
        }else{
            stk.push(ch);
        }
        
    }
    
    if (!stk.empty())
        answer = false;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}