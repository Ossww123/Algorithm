def dfs(y, x, dir, turn, desserts):
    global max_value, start_y, start_x

    if len(desserts) > 1 and y == start_y and x == start_x and turn == 3:
        max_value = max(max_value, len(desserts))
        return

    if turn > 3:
        return

    for i in range(2):
        ny = y + dy[(dir + i) % 4]
        nx = x + dx[(dir + i) % 4]

        if 0 <= ny < N and 0 <= nx < N and cafe[ny][nx] not in desserts:
            dfs(ny, nx, (dir + i) % 4, turn + i, desserts | {cafe[ny][nx]})


T = int(input())
dy = [1, 1, -1, -1]
dx = [1, -1, -1, 1]

for tc in range(1, T + 1):
    N = int(input())
    cafe = [list(map(int, input().split())) for _ in range(N)]
    max_value = -1

    for i in range(N - 2):
        for j in range(1, N - 1):
            start_y, start_x = i, j
            dfs(i, j, 0, 0, set())

    print(f'#{tc} {max_value}')