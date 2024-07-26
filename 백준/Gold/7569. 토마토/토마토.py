import sys
from collections import deque

dirs = [(0, 0, 1), (0, 0, -1), (0, 1, 0), (0, -1, 0), (1, 0, 0), (-1, 0, 0) ]
w, h, d = map(int, sys.stdin.readline().rstrip().split())

queue = deque([])
matrix = []
for z in range(d):
    layer = []
    for y in range(h):
        row = list(map(int, sys.stdin.readline().rstrip().split()))
        layer.append(row)
        for x in range(w):
            if row[x] == 1:
                queue.append((z, y, x))
    matrix.append(layer)

count = 0

while queue:
    start_z, start_y, start_x = queue.popleft()

    for dz, dy, dx in dirs:
        nz, ny, nx = start_z + dz, start_y + dy, start_x + dx
        if nz < 0 or nz >= d or ny < 0 or ny >= h or nx < 0 or nx >= w:
            continue
        if matrix[nz][ny][nx] >= 1 or matrix[nz][ny][nx] == -1:
            continue
        queue.append((nz, ny, nx))
        matrix[nz][ny][nx] = matrix[start_z][start_y][start_x] + 1
        if matrix[nz][ny][nx] - 1 > count : count = matrix[nz][ny][nx] - 1

win = True

for z in range(d):
    for y in range(h):
        for x in range(w):
            if not matrix[z][y][x]:
                win = False

if win:
    print(count)
else:
    print(-1)