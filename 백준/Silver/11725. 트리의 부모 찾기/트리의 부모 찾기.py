from collections import deque

N = int(input())

connected_node = {}
for _ in range(N-1):
    a, b = map(int, input().split())
    if a in connected_node:
        connected_node[a].append(b)
    else:
        connected_node[a] = [b]
    if b in connected_node:
        connected_node[b].append(a)
    else:
        connected_node[b] = [a]

visited = [0] * (N+1)
visited[1] = -1
que = deque([1])

while que:
    start_node = que.popleft()

    for end_node in connected_node[start_node]:
        if visited[end_node]:
            continue
        visited[end_node] = start_node
        que.append(end_node)

for i in visited[2:]:
    print(i)