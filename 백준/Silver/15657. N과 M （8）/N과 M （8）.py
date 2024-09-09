def solve(lst = [], idx = 0):
    if len(lst) ==M:
        print(*lst)
        return

    for i in range(idx, N):
        lst.append(num_lst[i])
        solve(lst, i)
        lst.pop()


N, M =map(int, input().split())
num_lst = list(map(int,input().split()))
num_lst.sort()
solve()