from collections import deque
from pprint import pprint as pp

N, M = map(int, input().split())
arr = [list(map(int, input())) for _ in range(N)]

DIRS = [(0, 1), (0, -1), (1, 0), (-1, 0)]

# 3차원 배열로 변경: [y][x][벽을 부쉈는지 여부]
visited = [[[0, 0] for _ in range(M)] for _ in range(N)]
dist = [[[0, 0] for _ in range(M)] for _ in range(N)]

que = deque([(0, 0, 0)])  # (y, x, 벽을 부쉈는지 여부)
visited[0][0][0] = 1
dist[0][0][0] = 1

while que:
    sy, sx, broken = que.popleft()

    if sy == N - 1 and sx == M - 1:
        print(dist[sy][sx][broken])
        exit()

    for dy, dx in DIRS:
        ny, nx = sy + dy, sx + dx
        if ny < 0 or ny >= N or nx < 0 or nx >= M:
            continue

        # 벽이 아닌 경우
        if arr[ny][nx] == 0 and not visited[ny][nx][broken]:
            visited[ny][nx][broken] = 1
            dist[ny][nx][broken] = dist[sy][sx][broken] + 1
            que.append((ny, nx, broken))

        # 벽인 경우, 아직 벽을 부수지 않았다면
        elif arr[ny][nx] == 1 and broken == 0 and not visited[ny][nx][1]:
            visited[ny][nx][1] = 1
            dist[ny][nx][1] = dist[sy][sx][broken] + 1
            que.append((ny, nx, 1))

print(-1)  # 도달할 수 없는 경우