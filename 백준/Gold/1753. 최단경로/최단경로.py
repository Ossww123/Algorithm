import heapq

INF = 1e18

N, M = map(int, input().split())
start_node = int(input())
edges = [[] for _ in range(N + 1)]
for _ in range(M):
    u, v, w = map(int, input().split())
    edges[u].append((v, w))

distance = [INF] * (N + 1)
distance[start_node] = 0

pq = []
heapq.heappush(pq, (0, start_node))

while pq:
    current_distance, current_node = heapq.heappop(pq)

    if distance[current_node] < current_distance:
        continue

    for neighbor, weight in edges[current_node]:
        new_distance = current_distance + weight
        if new_distance < distance[neighbor]:
            distance[neighbor] = new_distance
            heapq.heappush(pq, (new_distance, neighbor))

for i in range(1, N + 1):
    if distance[i] == INF:
        print('INF')
    else:
        print(distance[i])
