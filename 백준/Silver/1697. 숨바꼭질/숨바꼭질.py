N, K = map(int, input().split())

visited = [False] * 200001
visited[N] = True
level = 0
queue = [(N, level)]
next_levels = []
result = 0

while not visited[K]:
    start = queue.pop(0)
    level = start[1] + 1
    if start[0] > 0: next_levels.append(start[0] - 1)
    if start[0] < 200000: next_levels.append(start[0] + 1)
    if 2 * start[0] < 200001: next_levels.append(2 * start[0])

    for next_level in next_levels:
        if visited[next_level]:
            continue
        queue.append((next_level, level))
        visited[next_level] = True
        if next_level == K:
            result = level
            break
    next_levels = []

print(result)