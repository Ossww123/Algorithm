DIRS = [(0, 1), (0, -1), (1, 0), (-1, 0)]

def solve(y, x, num, idx=0):
    if idx == 6:
        maked.add(num)
        return

    for dy, dx in DIRS:
        ny, nx = dy + y, dx + x
        if ny < 0 or ny >= 4 or nx < 0 or nx >= 4:
            continue
        solve(ny, nx, num+array[ny][nx], idx+1)




T = int(input())

for tc in range(1, T + 1):
    array = [list(input().split()) for _ in range(4)]

    maked = set()
    for y in range(4):
        for x in range(4):
            solve(y, x, array[y][x])

    print(f'#{tc} {len(maked)}')
