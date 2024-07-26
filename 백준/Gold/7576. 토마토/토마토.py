import sys
from collections import deque

dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
w, h = map(int, sys.stdin.readline().rstrip().split())

queue = deque([])
matrix = []
for y in range(h):
    row = list(map(int, sys.stdin.readline().rstrip().split()))
    matrix.append(row)
    for x in range(w):
        if row[x] == 1:
            queue.append((y, x))

count = 0

while queue:
    start_y, start_x = queue.popleft()

    for dy, dx in dirs:
        ny, nx = start_y + dy, start_x + dx
        if ny < 0 or ny >= h or nx < 0 or nx >= w:
            continue
        if matrix[ny][nx] >= 1 or matrix[ny][nx] == -1:
            continue
        queue.append((ny, nx))
        matrix[ny][nx] = matrix[start_y][start_x] + 1
        if matrix[ny][nx] - 1 > count : count = matrix[ny][nx] - 1

win = True

for y in range(h):
    for x in range(w):
        if not matrix[y][x]:
            win = False

if win:
    print(count)
else:
    print(-1)