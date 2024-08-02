N, M = map(int, input().split())
lst = sorted(list(map(int, input().split())))
visited = [False] * N
temp = []

def backtrack(idx):
    if len(temp) == M:
        print(*temp)
        return

    remember = 0
    for i in range(idx, N):
        if not visited[i] and remember != lst[i]:
            visited[i] = True
            temp.append(lst[i])
            remember = lst[i]
            backtrack(i + 1)
            visited[i] = False
            temp.pop()

backtrack(0)
