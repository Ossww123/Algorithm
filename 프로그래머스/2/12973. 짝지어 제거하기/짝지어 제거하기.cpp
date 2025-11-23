#include <bits/stdc++.h>

using namespace std;

int solution(string s)
{
    stack<char> stk;
    
    for(char c : s){
        if (stk.empty()){
            stk.push(c);
        }
        else{
            char tc = stk.top();
            if (tc == c){
                stk.pop();
            }
            else{
                stk.push(c);
            }
        }
    }
    
    if (stk.empty()) return 1;
    else return 0;
}