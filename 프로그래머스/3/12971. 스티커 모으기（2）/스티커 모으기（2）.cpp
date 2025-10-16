#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> sticker)
{
    int n = sticker.size();
    if (n == 1) return sticker[0];
    if (n == 2) return max(sticker[0], sticker[1]);
    
    int answer =0;
    
    // dp[i] : max(dp[i-2] + S[i], dp[i-1])
    // sticker[0]을 뗀 경우
    vector<int> dp1(n, 0);
    dp1[0] = sticker[0];
    dp1[1] = max(sticker[0], sticker[1]);
    for (int i = 2; i <= n - 2; ++i) {
        dp1[i] = max(dp1[i - 1], dp1[i - 2] + sticker[i]);
    }
    
    // sticker[0]을 안 뗀 경우
    vector<int> dp2(n, 0);
    dp2[0] = 0;
    dp2[1] = sticker[1];
    for (int i = 2; i <= n - 1; ++i) {
        dp2[i] = max(dp2[i - 1], dp2[i - 2] + sticker[i]);
    }

    answer = max(dp1[n-2], dp2[n-1]);
    
    return answer;
}