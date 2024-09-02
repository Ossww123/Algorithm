# 남은 횟수의 경우의 수
def remained(M):
    total = 2 ** M
    while M > 1:
        total *= M
        M -= 1

    return total


# 순열
def permutation(remain, idx=0, w_diff=0):
    global result
    global memo

    # 메모이제이션 체크
    state = (tuple(visited), remain, idx, w_diff)
    if state in memo:
        result += memo[state]
        return

    # 왼쪽과 오른쪽의 무게차보다 남아있는 추의 무게합이 적으면
    if remain <= w_diff:
        remaining_count = remained(N - idx)
        result += remaining_count
        memo[state] = remaining_count
        return

    current_result = result

    # 순열, 왼쪽에 올리면 + weights[i], 오른쪽에 올리면 - weights[i]
    for i in range(N):
        if not visited[i]:
            visited[i] = True
            permutation(remain - weights[i], idx + 1, w_diff + weights[i])
            visited[i] = False
            if w_diff >= weights[i]:
                visited[i] = True
                permutation(remain - weights[i], idx + 1, w_diff - weights[i])
                visited[i] = False

    # 결과 계산 후 메모이제이션에 저장
    memo[state] = result - current_result

T = int(input())

for tc in range(1, T + 1):
    N = int(input())
    weights = list(map(int, input().split()))
    visited = [False] * N
    all_weight = sum(weights)
    memo = {}

    result = 0

    permutation(all_weight)
    print(f'#{tc} {result}')
