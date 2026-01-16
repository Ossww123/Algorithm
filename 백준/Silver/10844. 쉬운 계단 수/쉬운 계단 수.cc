#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    
    ll MOD = 1000000000;
    
    vector<vector<ll>> nums(n + 1, vector<ll>(10,0));
    
    for (int i=1;i<=9;i++)
    {
        nums[1][i] = 1;
    }
    
    for (int i=2; i<=n; i++)
    {
        for(int j=0;j<=9;j++)
        {
            if (j == 0)
            {
                nums[i][j] = nums[i-1][1] % MOD;
            }
            else if (j == 9)
            {
                nums[i][j] = nums[i-1][8] % MOD;
            }
            else
            {
                nums[i][j] = (nums[i-1][j-1] + nums[i-1][j+1]) % MOD;
            }
        }
    }
    
    ll answer = 0;
    
    for(ll num : nums[n])
    {
        answer += num;
    }
    
    answer = answer % MOD;
    
    cout << answer;
    
    return 0;
}