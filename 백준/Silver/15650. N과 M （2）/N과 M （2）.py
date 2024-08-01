N, M = map(int, input().split())

def backtrack(result, idx):
    if len(result) == M:
        print(*result)
        return

    for i in range(idx, N+1):
        if not i in result:
            result.append(i)
            idx += 1
            backtrack(result, i)
            idx -= 1
            result.pop()

backtrack([], 1)