N, M = map(int, input().split())

def backtrack(result):
    if len(result) == M:
        print(*result)
        return

    for i in range(1, N+1):
        result.append(i)
        backtrack(result)
        result.pop()

backtrack([])