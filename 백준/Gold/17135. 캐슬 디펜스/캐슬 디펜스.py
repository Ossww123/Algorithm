from collections import deque
import copy
from itertools import combinations

dirs = [(0, -1), (-1, 0), (0, 1)]  # 왼쪽, 위, 오른쪽 순서로 탐색
N, M, D = map(int, input().split())
game_map = [list(map(int, input().split())) for _ in range(N)]
max_kills = 0


def bfs(archer, arr):
    start_y, start_x = N, archer
    que = deque([(start_y, start_x, 0)])
    visited = set()

    while que:
        y, x, dist = que.popleft()

        if dist > D:
            break

        if y < N and arr[y][x] == 1:
            return (y, x)

        for dy, dx in dirs:
            ny, nx = y + dy, x + dx
            if 0 <= ny < N and 0 <= nx < M and (ny, nx) not in visited:
                visited.add((ny, nx))
                que.append((ny, nx, dist + 1))

    return None


def shoot_enemy(archers, arr):
    game_map = copy.deepcopy(arr)
    cnt = 0

    for _ in range(N):
        targets = set()
        for archer in archers:
            target = bfs(archer, game_map)
            if target:
                targets.add(target)

        for target in targets:
            if game_map[target[0]][target[1]] == 1:
                game_map[target[0]][target[1]] = 0
                cnt += 1

        game_map = [[0] * M] + game_map[:-1]

    return cnt


def solve():
    global max_kills
    for archers in combinations(range(M), 3):
        kills = shoot_enemy(archers, game_map)
        max_kills = max(max_kills, kills)


solve()
print(max_kills)