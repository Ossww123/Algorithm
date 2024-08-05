T = int(input())

for tc in range(1, T + 1):
    N = int(input())
    if N == 1:
        a = int(input())
        b = int(input())
        print(max(a, b))
    else:
        sticker = [list(map(int, input().split())) for _ in range(2)]
        dp = [[0]*N for _ in range(2)]
        dp[0][0] = sticker[0][0]
        dp[1][0] = sticker[1][0]
        dp[0][1] = sticker[1][0] + sticker[0][1]
        dp[1][1] = sticker[0][0] + sticker[1][1]

        for i in range(2, N):
            dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + sticker[0][i]
            dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + sticker[1][i]

        print(max(dp[0][N-1], dp[1][N-1]))