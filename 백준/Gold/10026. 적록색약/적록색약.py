from collections import deque
dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]

def rgb_dfs(matrix, N, color):
    cnt = 0
    visited = [[False] * N for _ in range(N)]

    for y in range(N):
        for x in range(N):
            if matrix[y][x] in color and not visited[y][x]:
                stk = [(y, x)]
                visited[y][x] = True
                cnt += 1

                while stk:
                    start_y, start_x = stk.pop()
                    for dy, dx in dirs:
                        ny = start_y + dy
                        nx = start_x + dx
                        if ny < 0 or ny >= N or nx < 0 or nx >= N:
                            continue
                        if matrix[ny][nx] not in color or visited[ny][nx]:
                            continue
                        stk.append((ny, nx))
                        visited[ny][nx] = True
    return cnt

length = int(input())
layer = []
for _ in range(length):
    row = list(input())
    layer.append(row)

b_component = rgb_dfs(layer, length, ['B'])
normal = b_component + rgb_dfs(layer, length, ['R']) + rgb_dfs(layer, length, ['G'])
redgreen = b_component + rgb_dfs(layer, length, ['G', 'R'])
print(normal, redgreen)
