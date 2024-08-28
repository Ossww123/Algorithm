def stair_num(pos, last, used):

    # 기본 케이스: 모든 칸을 채운 경우
    if pos == N:
        return 1 if used == (1 << 10) - 1 else 0

    if dp[pos][last][used] != -1:
        return dp[pos][last][used]

    ret = 0
    if last > 0:
        ret += stair_num(pos + 1, last - 1, used | (1 << (last - 1)))
    if last < 9:
        ret += stair_num(pos + 1, last + 1, used | (1 << (last + 1)))

    dp[pos][last][used] = ret
    return ret


# 입력 받기
N = int(input())

# DP 테이블 초기화
dp = [[[-1] * (1 << 10) for _ in range(10)] for _ in range(N)]

# 결과 출력
result = sum(stair_num(1, i, 1 << i) for i in range(1, 10))
print(result % 1000000000)
