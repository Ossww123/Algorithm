import heapq

n, m, r = map(int, input().split())  # n : 노드의 수, m : 수색 범위, r : 간선의 수
item_nums = list(map(int, input().split()))
edges = [[] for _ in range(n)]

for _ in range(r):
    u, v, w = map(int, input().split())

    # 노드 번호를 0번부터
    u -= 1
    v -= 1

    # 양방향 간선
    edges[u].append((v, w))
    edges[v].append((u, w))


# 다익스트라 알고리즘
def dijkstra(start):
    distances = [1e19] * n
    distances[start] = 0
    pq = [(distances[start], start)]
    visited = [False] * n

    for _ in range(n - 1):
        if not pq:
            break
        distance, node = heapq.heappop(pq)
        visited[node] = True

        for edge, weight in edges[node]:
            if visited[edge]:
                continue
            distances[edge] = min(distances[edge], distance + weight)
            heapq.heappush(pq, (distances[edge], edge))

    # 수색 범위 m 내의 아이템 갯수를 모두 더함
    total = 0
    for i in range(n):
        if distances[i] <= m:
            total += item_nums[i]

    return total


# 0 ~ n-1 번 노드 중 가장 아이템을 많이 모을수 있는 경우 탐색
max_value = 0
for i in range(n):
    max_value = max(max_value, dijkstra(i))

print(max_value)
