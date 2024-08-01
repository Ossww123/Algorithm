N, M = map(int, input().split())
lst = list(map(int, input().split()))
lst.sort()

def backtrack(result):
    global lst
    if len(result) == M:
        print(*result)
        return

    for i in lst:
        if not i in result:
            result.append(i)
            backtrack(result)
            result.pop()

backtrack([])