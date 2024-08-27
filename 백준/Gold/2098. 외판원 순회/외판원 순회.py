import sys

IMPOSSIBLE = 1000000000


def TSP(current, visited):
    if dp[current][visited] != -1:
        return dp[current][visited]

    # 기본 케이스: 모든 도시를 방문한 경우
    if visited == (1 << N) - 1:
        if W[current][0] != 0:
            return W[current][0]
        return IMPOSSIBLE  # 시작점으로 돌아갈 수 없음

    ret = IMPOSSIBLE
    for i in range(N):
        # i번 도시를 이미 방문했거나 i번 도시로 갈 수 없는 경우
        if visited & (1 << i) or W[current][i] == 0:
            continue
        # 그 외의 경우
        ret = min(ret, TSP(i, visited | (1 << i)) + W[current][i])

    dp[current][visited] = ret
    return ret


# 입력 받기
N = int(sys.stdin.readline())
W = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

# DP 테이블 초기화
dp = [[-1] * (1 << N) for _ in range(N)]

# 결과 출력
print(TSP(0, 1))