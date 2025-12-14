#include <string>
#include <vector>

using namespace std;

int MAXSCORE = 10;

vector<int> infoApitch(11, 0);
vector<bool> isRionWin(11, false);
vector<int> answer(11, 0);
int maxDiff = 0;

bool better(const vector<int>& a, const vector<int>& b)
{
    for (int i = 10; i >= 0; --i)
    {
        if (a[i] != b[i]) return a[i] > b[i];
    }
    return false;
}

void calDiff(int n)
{
    int rionScore = 0;
    int apitchScore = 0;
    for (int i=0; i<11 ; i++)
    {
        if (isRionWin[i])
        {
            rionScore += (MAXSCORE - i);
        }
        else if (infoApitch[i] > 0)
        {
            apitchScore += (MAXSCORE - i);
        }
    }
    
    int diffScore = rionScore - apitchScore;
    if (diffScore <= 0) return;
    
    vector<int> cand(11, 0);
    int totalArrow = 0;
    for (int i = 0; i < 11; i++)
    {
        if (isRionWin[i])
        {
            cand[i] = infoApitch[i] + 1;
            totalArrow += cand[i];
        }
    }
    
    if (totalArrow < n)
        cand[10] += (n - totalArrow);

    if (diffScore > maxDiff || (diffScore == maxDiff && better(cand, answer)))
    {
        maxDiff = diffScore;
        answer = cand;
    }
}

void dfs(int currIndex, int remainedArrow, int n)
{
    if (currIndex >= 10)
    {
        calDiff(n);
        return;
    }
    
    if (remainedArrow - (infoApitch[currIndex] + 1) >= 0)
    {
        isRionWin[currIndex] = true;
        dfs(currIndex + 1, remainedArrow - (infoApitch[currIndex] + 1), n);
        isRionWin[currIndex] = false;
    }
    
    dfs(currIndex + 1, remainedArrow, n);
}

vector<int> solution(int n, vector<int> info)
{
    for(int i=0; i<11; i++)
    {
        infoApitch[i] = info[i];
    }

    dfs(0, n, n);
    
    int totalArrow = 0;
    for (int i=0;i<11;i++)
    {
        totalArrow += answer[i];
    }
    
    if (maxDiff == 0)
        return {-1};
    
    return answer;
}