def remained(M):
    total = 2 ** M
    while M > 1:
        total *= M
        M -= 1

    return total


def permutation(idx=0,w_diff=0, used=0):
    global result

    if all_weight - used < w_diff:
        result += remained(N - idx)
        return

    if idx == N:
        result += 1
        return

    for i in range(N):
        if not visited[i]:
            for j in range(2):
                if j == 0:
                    visited[i] = True
                    permutation(idx + 1, w_diff + weights[i], used + weights[i])
                    visited[i] = False
                elif j == 1 and w_diff >= weights[i]:
                    visited[i] = True
                    permutation(idx + 1, w_diff - weights[i], used + weights[i])
                    visited[i] = False


T = int(input())

for tc in range(1, T+1):
    N = int(input())
    weights = list(map(int, input().split()))
    visited = [False] * N
    all_weight = sum(weights)

    result = 0

    permutation()
    print(f'#{tc} {result}')