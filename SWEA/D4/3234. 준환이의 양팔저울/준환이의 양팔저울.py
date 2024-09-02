# 남은 횟수의 경우의 수
def remained(M):
    total = 2 ** M
    while M > 1:
        total *= M
        M -= 1

    return total


# 순열
def permutation(remain, idx=0,w_diff=0):
    global result

    # 왼쪽과 오른쪽의 무게차보다 남아있는 추의 무게합이 적으면
    if remain <= w_diff:
        result += remained(N - idx)
        return

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


T = int(input())

for tc in range(1, T+1):
    N = int(input())
    weights = list(map(int, input().split()))
    visited = [False] * N
    all_weight = sum(weights)

    result = 0

    permutation(all_weight)
    print(f'#{tc} {result}')