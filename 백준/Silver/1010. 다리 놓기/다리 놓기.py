T = int(input())

for tc in range(T):
    N, M = map(int, input().split())

    dp = [[1] * (i + 1) for i in range(M + 1)]
    for y in range(1, M + 1):
        for x in range(1, y):
            dp[y][x] = dp[y - 1][x - 1] + dp[y - 1][x]

    print(dp[M][N])
