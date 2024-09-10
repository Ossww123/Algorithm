DIRS = [(0, 1), (0, -1), (1, 0), (-1,0)]

T = int(input())

for tc in range(1, T+1):
    N, M , K = map(int,input().split())
    cabbage_field = [[0] * M for _ in range(N)]
    for _ in range(K):
        a, b = map(int,input().split())
        cabbage_field[a][b] = 1

    visited = [[False] * M for _ in range(N)]

    stk = []
    cnt = 0
    for y in range(N):
        for x in range(M):
            if cabbage_field[y][x] == 1:
                if visited[y][x]:
                    continue
                stk.append((y, x))
                cnt += 1
                while stk:
                    sy, sx = stk.pop()
                    visited[sy][sx] = True

                    for dy, dx in DIRS:
                        ny, nx = dy + sy, dx + sx
                        if ny < 0 or ny >= N or nx < 0 or nx >= M:
                            continue
                        if visited[ny][nx] or cabbage_field[ny][nx] == 0:
                            continue
                        stk.append((ny, nx))
    
    print(cnt)