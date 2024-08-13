N, S = map(int,input().split())
lst = list(map(int, input().split()))

cnt = 0
def backtrack(result = [], idx = 0):
    global cnt

    if idx == N:
        if result and sum(result) == S:
            cnt += 1
        return

    for j in range(2):
        if j == 0:
            result.append(lst[idx])
            backtrack(result, idx + 1)
            result.pop()
        else:
            backtrack(result, idx + 1)

backtrack()
print(cnt)