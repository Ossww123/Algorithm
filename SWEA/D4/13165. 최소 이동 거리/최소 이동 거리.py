INF = 1_000_000_000_000

T = int(input())

for tc in range(1, T+1):
    N, E = map(int,input().split())

    distances = [INF]*(N+1)
    distances[0] = 0
    edges = []
    for _ in range(E):
        u, v, w = map(int, input().split())
        edges.append((u, v, w))

    for _ in range(N):
        for s_node, e_node, weight in edges:
            temp = distances[s_node] + weight
            distances[e_node] = min(distances[e_node], temp)

    print(f'#{tc} {distances[N]}')
