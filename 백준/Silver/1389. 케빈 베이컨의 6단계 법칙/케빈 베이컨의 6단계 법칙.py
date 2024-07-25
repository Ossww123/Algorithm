N, M = map(int, input().split())
edges = {}
for _ in range(M):
    a, b = map(int, input().split())

    if a in edges: edges[a].append(b)
    else: edges[a] = [b]
    if b in edges: edges[b].append(a)
    else: edges[b] = [a]

count = [0] * N
for user in range(1, N+1):
    visited = [False] * N
    level = 0
    queue = [(user, level)]
    visited[user - 1] = True


    while queue:
        start_node = queue.pop(0)


        for edge in edges[start_node[0]]:
            if visited[edge - 1]:
                continue
            level = start_node[1]+1
            queue.append((edge, level))
            count[user-1] += level
            visited[edge - 1] = True


print(count.index(min(count)) + 1)