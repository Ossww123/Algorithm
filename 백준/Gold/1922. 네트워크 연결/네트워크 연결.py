import sys
N = int(input())
M = int(input())
edges = []
for _ in range(M):
    a, b, c = map(int, sys.stdin.readline().split())
    edges.append((a-1, b-1, c))

edges.sort(key=lambda x: x[2])

parent = list(range(N))
def find(x):
    if parent[x] != x:
        parent[x] = find(parent[x])
    return parent[x]

result = 0
for u, v, w in edges:
    root_u, root_v = find(u), find(v)
    if root_u != root_v:
        parent[root_u] = root_v
        result += w
        N -= 1
        if N == 1:
            break

print(result)