N, M = map(int, input().split())
lst = list(map(int, input().split()))
lst.sort() # 1 7 8 9

def backtrack(result):
    if len(result) == M:
        print(*result)
        return

    for i in range(N):
        result.append(lst[i])
        backtrack(result)
        result.pop()


backtrack([])