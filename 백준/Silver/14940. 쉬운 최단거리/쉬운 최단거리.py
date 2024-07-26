dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]

h, w = map(int, input().split())
matrix = []

for y in range(h):
    row = list(map(int, input().split()))
    matrix.append(row)
    if 2 in row:
        two_y, two_x = y, row.index(2)

visited = [[False] * w for _ in range(h)]

for y in range(h):
    for x in range(w):
        if matrix[y][x] == 1:
            matrix[y][x] = -1

# -----------------------------------------------
matrix[two_y][two_x] = 0
visited[two_y][two_x] = True
queue = [(two_y, two_x)]

while queue:
    start_y, start_x = queue.pop(0)

    for dy, dx in dirs:
        ny = start_y + dy
        nx = start_x + dx

        if ny < 0 or ny >= h or nx < 0 or nx >= w:
            continue
        if visited[ny][nx]:
            continue
        if matrix[ny][nx] == 0:
            continue

        queue.append((ny, nx))
        visited[ny][nx] = True
        matrix[ny][nx] = matrix[start_y][start_x] + 1

for idx in range(h):
    print(' '.join(map(str, matrix[idx])))
