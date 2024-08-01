N = int(input())

integer_tri = [[int(input())]]
if N > 1:
    for _ in range(1, N):
        integer_tri.append(list(map(int, input().split())))

dp = [[0]*i for i in range(1, N+1)]
dp[N-1] = integer_tri[N-1]

# dp[4][0] + integer_tri[3][0], dp[4][1] + integer_tri[3][0] 비교해서 높은 값을 dp[3][0]에 넣기
for i in range(N-1, 0, -1):
    for j in range(i):
        dp[i-1][j] = max(dp[i][j] + integer_tri[i-1][j], dp[i][j+1] + integer_tri[i-1][j])

print(dp[0][0])