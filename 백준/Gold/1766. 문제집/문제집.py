import heapq

# topological_sort

N, M = map(int, input().split())
indegree = [0] * N
adj = [[] for _ in range(N)]

for i in range(M):
    before, after = map(lambda x: int(x)-1, input().split())
    adj[before].append(after)
    indegree[after] += 1

heap = []
for i in range(N):
    if indegree[i] == 0:
        heapq.heappush(heap, i)

result = []
for _ in range(N):
    curr = heapq.heappop(heap)
    result.append(curr+1)
    for next_node in adj[curr]:
        indegree[next_node] -= 1

        if indegree[next_node] == 0:
            heapq.heappush(heap, next_node)

print(*result)

