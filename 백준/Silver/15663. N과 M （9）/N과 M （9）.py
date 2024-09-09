def solve(lst=[]):
    if len(lst) == M:
        print(*lst)
        return

    a = -1

    for i in range(N):
        if num_lst[i] != a and visited[i] == False:
            a = num_lst[i]
            visited[i] = True
            lst.append(num_lst[i])
            solve(lst)
            lst.pop()
            visited[i] = False




N, M = map(int, input().split())
num_lst = list(map(int, input().split()))
num_lst.sort()
visited = [False] * N
solve()
