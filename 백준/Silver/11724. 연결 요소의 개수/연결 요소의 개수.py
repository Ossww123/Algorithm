N, M = map(int, input().split())

edges = {}

for _ in range(M):
    a, b = map(int, input().split())
    if a in edges: edges[a].append(b)
    else: edges[a] = [b]
    if b in edges: edges[b].append(a)
    else: edges[b] = [a]


visited = [False for _ in range(N)]
component = 0

for node in range(N):
    if not visited[node]:
        stk = [node+1]
        component += 1
        while stk:
            start_node = stk.pop()
            if visited[start_node-1]:
                continue
            visited[start_node-1] = True
            
            if not start_node in edges:
                continue
                
            for edge in edges[start_node]:
                if visited[edge-1]:
                    continue
                stk.append(edge)

print(component)