from collections import deque

dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]


def cnt_island(array, height, width):
    visited = [[False] * width for _ in range(height)]
    islands = []

    for y in range(height):
        for x in range(width):
            if array[y][x] == 1 and not visited[y][x]:
                island = []
                queue = deque([(y, x)])
                visited[y][x] = True

                while queue:
                    cy, cx = queue.popleft()
                    island.append((cy, cx))

                    for dy, dx in dirs:
                        ny, nx = cy + dy, cx + dx
                        if 0 <= ny < height and 0 <= nx < width and array[ny][nx] == 1 and not visited[ny][nx]:
                            visited[ny][nx] = True
                            queue.append((ny, nx))

                islands.append(island)

    return islands


def build_bridge(islands, all_map, H, W):
    N = len(islands)
    bridges = []

    for i in range(N - 1):
        for j in range(i + 1, N):
            min_distance = float('inf')
            for y1, x1 in islands[i]:
                for y2, x2 in islands[j]:
                    if y1 == y2:
                        distance = abs(x1 - x2) - 1
                        if distance > 1:
                            is_valid = True
                            for x in range(min(x1, x2) + 1, max(x1, x2)):
                                if all_map[y1][x] != 0:
                                    is_valid = False
                                    break
                            if is_valid:
                                min_distance = min(min_distance, distance)
                    elif x1 == x2:
                        distance = abs(y1 - y2) - 1
                        if distance > 1:
                            is_valid = True
                            for y in range(min(y1, y2) + 1, max(y1, y2)):
                                if all_map[y][x1] != 0:
                                    is_valid = False
                                    break
                            if is_valid:
                                min_distance = min(min_distance, distance)

            if min_distance < float('inf'):
                bridges.append((i, j, min_distance))

    return bridges


def find(parent, x):
    if parent[x] != x:
        parent[x] = find(parent, parent[x])
    return parent[x]


def union(parent, a, b):
    a = find(parent, a)
    b = find(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b


H, W = map(int, input().split())
all_map = [list(map(int, input().split())) for _ in range(H)]

islands = cnt_island(all_map, H, W)
edges = build_bridge(islands, all_map, H, W)

edges.sort(key=lambda x: x[2])

num_islands = len(islands)
parent = list(range(num_islands))

result = 0
connected_islands = 1

for u, v, w in edges:
    if find(parent, u) != find(parent, v):
        union(parent, u, v)
        result += w
        connected_islands += 1
        if connected_islands == num_islands:
            break

if connected_islands == num_islands:
    print(result)
else:
    print(-1)