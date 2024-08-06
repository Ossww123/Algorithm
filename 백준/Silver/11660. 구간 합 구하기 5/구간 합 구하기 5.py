N, M = map(int, input().split())

arr = [list(map(int, input().split())) for _ in range(N)]
dp = [[0] * N for _ in range(N)]
dp[0][0] = arr[0][0]
for i in range(1, N):
    dp[i][0] = dp[i-1][0] + arr[i][0]
    dp[0][i] = dp[0][i-1] + arr[0][i]

for y in range(1, N):
    for x in range(1, N):
        dp[y][x] = dp[y-1][x] + dp[y][x-1] - dp[y-1][x-1] + arr[y][x]

for _ in range(M):
    y1, x1, y2, x2 = map(lambda x: int(x) - 1, input().split())

    if y1 == 0 and x1 == 0:
        result = dp[y2][x2]
    elif y1 == 0:
        result = dp[y2][x2] - dp[y2][x1-1]
    elif x1 == 0:
        result = dp[y2][x2] - dp[y1-1][x2]
    else:
        result = dp[y2][x2] - (dp[y2][x1-1] + dp[y1-1][x2] - dp[y1-1][x1-1])

    print(result)

