import heapq

N, M, X = map(int, input().split())

edges = [[] for _ in range(N + 1)]

for _ in range(M):
    u, v, w = map(int, input().split())
    edges[u].append((v, w))


def dijkstra(start):
    dist = [float('inf')] * (N + 1)
    dist[start] = 0
    pq = [(0, start)]

    while pq:
        d, node = heapq.heappop(pq)

        if d > dist[node]:
            continue

        for next_node, weight in edges[node]:
            cost = d + weight
            if cost < dist[next_node]:
                dist[next_node] = cost
                heapq.heappush(pq, (cost, next_node))

    return dist


result = 0
for i in range(1, N + 1):
    go = dijkstra(i)
    back = dijkstra(X)
    if go[X] + back[i] < float('inf'):
        result = max(result, go[X] + back[i])

print(result)