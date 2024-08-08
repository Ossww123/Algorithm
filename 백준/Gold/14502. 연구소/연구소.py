from collections import deque
import copy

dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]

H, W = map(int, input().split())

min_virus = 0xFFFF
result_arr = []

def BFS(array, value):
    global min_virus
    global result_arr
    que = deque([])
    visited = [[False] * W for _ in range(H)]
    cnt_virus = 0

    for y in range(H):
        for x in range(W):
            if array[y][x] == value and not visited[y][x]:
                que.append((y, x))
                visited[y][x] = True
                cnt_virus += 1

                while que:
                    start_y, start_x = que.popleft()

                    for dy, dx in dirs:
                        ny, nx = start_y + dy, start_x + dx
                        if ny < 0 or ny >= H or nx < 0 or nx >= W:
                            continue
                        if visited[ny][nx] or array[ny][nx] != 0:
                            continue
                        visited[ny][nx] = True
                        cnt_virus += 1
                        array[ny][nx] = value
                        que.append((ny, nx))
    if cnt_virus < min_virus:
        min_virus = cnt_virus
        result_arr = copy.deepcopy(array)

def backtrack(arr, before_y = -1, before_x = -1, i=0):
    if i == 3:
        arr_copy = copy.deepcopy(arr)
        BFS(arr_copy, 2)
        return

    for y in range(H):
        for x in range(W):
            if arr[y][x] == 0 and (y > before_y or (y == before_y and x > before_x)):
                arr[y][x] = 1
                backtrack(arr, y, x, i+1)
                arr[y][x] = 0


lab = [list(map(int, input().split())) for _ in range(H)]
backtrack(lab)

cnt = 0
for y in range(H):
    for x in range(W):
        if result_arr[y][x] == 0:
            cnt += 1

print(cnt)