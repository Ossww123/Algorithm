def solve(total, idx):
    global result

    if total >= K:
        if total == K:
            result += 1
        return

    if idx >= N:
        return

    solve(total + lst[idx], idx + 1)
    solve(total, idx + 1)

T = int(input())

for tc in range(1, T+1):
    N, K = map(int, input().split())
    lst = list(map(int,input().split()))
    result = 0
    solve(0, 0)

    print(f"#{tc} {result}")