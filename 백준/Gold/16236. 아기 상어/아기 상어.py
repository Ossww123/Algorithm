from collections import deque

dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]

N = int(input())
aquarium = [list(map(int, input().split())) for _ in range(N)]


def find_shark(arr):
    for y in range(N):
        for x in range(N):
            if arr[y][x] == 9:
                return (y, x)


def bfs(arr, shark_pos, shark_size, shark_ate_num, result):
    que = deque()
    que.append(shark_pos)
    visited = [[-1] * N for _ in range(N)]
    visited[shark_pos[0]][shark_pos[1]] = 0
    arr[shark_pos[0]][shark_pos[1]] = 0
    distance = 0xFFFF
    fish_pos = []

    while que:
        start_y, start_x = que.popleft()

        if distance > visited[start_y][start_x]:
            for dy, dx in dirs:
                ny, nx = start_y + dy, start_x + dx

                if ny < 0 or ny >= N or nx < 0 or nx >= N:
                    continue
                if visited[ny][nx] != -1 or arr[ny][nx] > shark_size:
                    continue

                if 0 < arr[ny][nx] < shark_size:
                    distance = visited[start_y][start_x] + 1
                    fish_pos.append((ny, nx))

                visited[ny][nx] = visited[start_y][start_x] + 1
                que.append((ny, nx))

    if fish_pos:
        fish_pos.sort()
        result += visited[fish_pos[0][0]][fish_pos[0][1]]
        shark_ate_num += 1
        shark_pos = (fish_pos[0][0], fish_pos[0][1])

        if shark_size == shark_ate_num:
            shark_size += 1
            shark_ate_num = 0
        return bfs(arr, shark_pos, shark_size, shark_ate_num, result)
    else:
        return result

print(bfs(aquarium, find_shark(aquarium), 2, 0, 0))