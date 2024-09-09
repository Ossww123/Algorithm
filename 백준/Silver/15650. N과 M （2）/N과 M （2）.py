def solve(lst = [], idx = 1):
    if len(lst) == M:
        print(*lst)
        return

    for i in range(idx, N+1):
        if i not in lst:
            lst.append(i)
            solve(lst, i)
            lst.pop()

N, M = map(int, input().split())
solve()