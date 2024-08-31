N, E = map(int, input().split())

edges = [[] for _ in range(N+1)]

for _ in range(E):
    u, v, w = map(int, input().split())
    edges[u].append((v, w))
    edges[v].append((u, w))

a, b = map(int, input().split())

one_dijk = [1e17] * (N+1)
a_dijk = [1e17] * (N+1)
b_dijk = [1e17] * (N+1)

one_dijk[1] = 0
a_dijk[a] = 0
b_dijk[b] = 0

def make_dijk(start, lst):
    used = []
    for _ in range(N-1):
        used.append(start)

        for node, weight in edges[start]:
            lst[node] = min(lst[node], lst[start] + weight)

        min_val = 1e17
        for i in range(1, N+1):
            if i in used:
                continue
            if lst[i] < min_val:
                start = i
                min_val = lst[i]



make_dijk(1, one_dijk)
# print('-----------------------')
make_dijk(a, a_dijk)
# print('-----------------------')
make_dijk(b, b_dijk)

# print(one_dijk)
# print(a_dijk)
# print(b_dijk)

aaa = one_dijk[a] + a_dijk[b] + b_dijk[N]
bbb = one_dijk[b] + b_dijk[a] + a_dijk[N]

result = min(aaa, bbb)
if result >= 1e17:
    print(-1)
else:
    print(result)