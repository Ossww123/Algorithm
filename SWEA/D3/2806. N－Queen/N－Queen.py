def solve(y=0):
    global result

    if y == N:
        result += 1
        return

    for x in range(N):
        if col[x]: continue
        if diag1[x + y]: continue
        if diag2[x - y + (N - 1)]: continue

        col[x] = True
        diag1[x + y] = True
        diag2[x - y + (N - 1)] = True

        solve(y + 1)

        col[x] = False
        diag1[x + y] = False
        diag2[x - y + (N - 1)] = False




T = int(input())

for tc in range(1, T + 1):
    N = int(input())

    col = [False] * N
    diag1 = [False] * (2 * N - 1)
    diag2 = [False] * (2 * N - 1)

    result = 0

    solve()

    print(f'#{tc} {result}')

