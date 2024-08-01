N, M = map(int, input().split())

def backtrack(result, idx):
    if len(result) == M:
        print(*result)
        return

    for i in range(idx, N+1):
        result.append(i)
        backtrack(result, i)
        result.pop()

backtrack([], 1)