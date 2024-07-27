from collections import deque

dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
H, W = map(int, input().split())

layer = []
visited = [[False] * W for _ in range(H)]

for _ in range(H):
    row = list(map(int, list(input())))
    layer.append(row)

queue = deque([(0, 0)]) # (1, 1)
visited[0][0] = True

while queue:
    s_y, s_x = queue.popleft()

    for dy, dx in dirs:
        ny, nx = s_y + dy, s_x + dx
        if ny < 0 or ny >= H or nx < 0 or nx >= W:
            continue
        if layer[ny][nx] == 0 or visited[ny][nx]:
            continue
        queue.append((ny, nx))
        visited[ny][nx] = True
        layer[ny][nx] = layer[s_y][s_x] + 1

print(layer[H-1][W-1])