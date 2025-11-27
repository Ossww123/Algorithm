#include <string>
#include <vector>

using namespace std;

typedef long long ll;

long long solution(int n) {
    vector<ll> dp(2001, -1);
    dp[0] = 1; dp[1] = 1;
    
    for (int i=2;i<=2000;i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 1234567;
    }
    
    return dp[n];
}