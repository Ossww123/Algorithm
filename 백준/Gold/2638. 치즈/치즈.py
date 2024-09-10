# from pprint import pprint as pp

DIRS = [(0, 1), (0, -1), (1, 0), (-1, 0)]

# 외부 공기 표시를 위해 (N+2)*(M+2) 배열 생성
N, M = map(int, input().split())
cheesemap = []
temp_lst = [0] * (M + 2)
cheesemap.append(temp_lst)

for _ in range(N):
    row = [0] + list(map(int, input().split())) + [0]
    cheesemap.append(row)

cheesemap.append(temp_lst)

N += 2
M += 2

cheese_num = 0
for y in range(N):
    for x in range(M):
        if cheesemap[y][x] == 1:
            cheese_num += 1

times = 0

while cheese_num > 0:
    stk = [(0, 0)]
    visited = [[0] * M for _ in range(N)]
    will_melt = []

    while stk:
        sy, sx = stk.pop()
        if visited[sy][sx] == 1:
            continue
        visited[sy][sx] = 1

        for dy, dx in DIRS:
            ny, nx = dy + sy, dx + sx
            if ny < 0 or ny >= N or nx < 0 or nx >= M:
                continue
            if cheesemap[ny][nx] == 1:
                visited[ny][nx] += 1
                if visited[ny][nx] == 2:
                    will_melt.append((ny, nx))
                continue

            if visited[ny][nx] == 1:
                continue

            stk.append((ny, nx))

    # print(will_melt)
    for y, x in will_melt:
        cheesemap[y][x] = 0
        cheese_num -= 1

    times += 1

print(times)