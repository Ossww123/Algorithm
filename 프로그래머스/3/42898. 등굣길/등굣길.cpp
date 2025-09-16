#include <string>
#include <vector>

using namespace std;

int divisor = 1000000007;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> dp(n + 1, vector<int>(m+1, 0));
    
    for (int i = 0; i < puddles.size(); ++i){
        int x = puddles[i][0];
        int y = puddles[i][1];
        dp[y][x] = -1;
    }
    
    dp[1][1] = 1;
    
    for (int y = 1; y <= n; ++y){
        for (int x = 1; x <= m; ++x){
            if (y == 1 && x == 1) continue;
            
            if (dp[y][x] == -1){
                dp[y][x] = 0;
                continue;
            }
            
            int from_up = (y > 1) ? dp[y-1][x] : 0;
            int from_left = (x > 1) ? dp[y][x-1] : 0;
            dp[y][x] = (from_up + from_left) % divisor;
        }
    }
    
    
    int answer = dp[n][m];
    
    return answer;
}