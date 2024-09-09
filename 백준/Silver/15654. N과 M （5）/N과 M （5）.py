def solve(lst = []):
    if len(lst) == M:
        print(*lst)
        return

    for i in range(N):
        if num_lst[i] not in lst:
            lst.append(num_lst[i])
            solve(lst)
            lst.pop()

N, M =map(int, input().split())
num_lst = list(map(int,input().split()))
num_lst.sort()
solve()