#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> values(n + 1, 0);
    
    for (int i=1; i<=n; i++)
    {
        cin >> values[i];
    }
    
    vector<int> dp(n + 1, 0);
    dp[1] = values[1];
    
    for (int i=2; i<=n ; i++)
    {
        int maxValue = 0;
        for (int j=1; j<=i; j++)
        {
            maxValue = max(maxValue, dp[i - j] + values[j]);
        }
        
        dp[i] = maxValue;
    }
    
    cout << dp[n];
    
    return 0;
}