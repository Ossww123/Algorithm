V, E = map(int, input().split())

edges = []
for _ in range(E):
    u, v, w = map(int,input().split())
    edges.append((u-1,v-1,w))

edges.sort(key=lambda x: x[2])


parent = list(range(V))
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
        V -= 1
        if V == 1:
            break

print(result)