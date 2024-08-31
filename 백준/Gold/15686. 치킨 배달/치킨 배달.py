N, M = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]

chickens = []
homes = []

for y in range(N):
    for x in range(N):
        if arr[y][x] == 1:
            homes.append((y, x))
        elif arr[y][x] == 2:
            chickens.append((y, x))

L = len(chickens)
K = len(homes)


def cal(ch_lst):
    dist = [1e17] * K
    for ch_y, ch_x in ch_lst:
        for idx in range(K):
            ho_y, ho_x = homes[idx]
            dist[idx] = min(dist[idx], abs(ch_y- ho_y) + abs(ch_x - ho_x))

    return sum(dist)

result = 1e17
def solve(lst = [], idx = 0):
    global result

    if len(lst) == M:
        result = min(result, cal(lst))
        return

    if idx >= L:
        return

    for i in range(2):
        if i == 0:
            lst.append(chickens[idx])
            solve(lst, idx+1)
            lst.pop()
        else:
            solve(lst, idx+1)

solve()

print(result)