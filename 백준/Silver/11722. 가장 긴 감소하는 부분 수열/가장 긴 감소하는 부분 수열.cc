#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    
    vector<int> numbers(n);
    for (int i=0; i<n; i++)
    {
        cin >> numbers[i];
    }
    
    vector<int> dp(n, 0);
    
    for (int i=0; i<n; i++)
    {
        int maxValue = 0;
        for (int j=0; j<i; j++)
        {
            if (numbers[j] > numbers[i])
            {
                maxValue = max(maxValue, dp[j]);
            }
        }
        
        dp[i] = maxValue + 1;
    }
    
    int answer = 0;
    for (int i=0; i<n; i++)
    {
        answer = max(answer, dp[i]);
    }
    
    cout << answer;
    
    return 0;
}