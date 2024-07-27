dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
N = int(input())

layer = []
visited = [[False] * N for _ in range(N)]
for _ in range(N):
    row = list(map(int, list(input())))
    layer.append(row)

result = []

for y in range(N):
    for x in range(N):
        if layer[y][x] == 1 and not visited[y][x]:
            stk = [(y, x)]
            count = 0
            while stk:
                start_y, start_x = stk.pop()
                if not visited[start_y][start_x]:
                    count += 1
                visited[start_y][start_x] = True

                for dy, dx in dirs:
                    ny, nx = start_y + dy, start_x + dx
                    if ny < 0 or ny >= N or nx < 0 or nx >= N:
                        continue
                    if visited[ny][nx] or layer[ny][nx] == 0:
                        continue
                    stk.append((ny, nx))
            result.append(count)

print(len(result))
for i in sorted(result):
    print(i)
