#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words)
{
    vector<int> answer;
    
    int playerNum = 1;
    int turn = 1;
    unordered_set<string> usedWords;
    vector<int> ans = {0, 0};
    
    char prevChar = words[0][0];
    
    for (string w : words)
    {
        // cout << "w: " << w << endl;
        // cout << "playerNum: " << playerNum << endl;
        // cout << "turn: " << turn << endl;
        // cout << "prebChar: " << prevChar << endl;
        
        if (usedWords.find(w) != usedWords.end())
        {
            ans[0] = playerNum;
            ans[1] = turn;
            break;
        }
        
        if (prevChar != w[0])
        {
            ans[0] = playerNum;
            ans[1] = turn;
            break;
        }
        
        if(playerNum == n) turn++;
        prevChar = w[w.length()-1];
        playerNum = playerNum + 1 == n ? n : (playerNum + 1) % n;
        usedWords.insert(w);
    }

    return ans;
}