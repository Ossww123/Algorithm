INF = float('inf')

def bellman_ford(N, edges, start=0):
    distance = [INF] * N
    distance[start] = 0

    # N-1번 반복
    for _ in range(N - 1):
        for u, v, w in edges:
            if distance[u] != INF and distance[u] + w < distance[v]:
                distance[v] = distance[u] + w
                visited.add(v)

    # 음수 사이클 검사
    for u, v, w in edges:
        if distance[u] != INF and distance[u] + w < distance[v]:
            return "YES"  # 음수 사이클 존재

    return "NO"  # 음수 사이클 없음

T = int(input())
for _ in range(T):
    N, M, W = map(int, input().split())
    edges = []

    # 도로 정보 입력
    for _ in range(M):
        S, E, T = map(int, input().split())
        edges.append((S-1, E-1, T))
        edges.append((E-1, S-1, T))  # 양방향

    # 웜홀 정보 입력
    for _ in range(W):
        S, E, T = map(int, input().split())
        edges.append((S-1, E-1, -T))  # 음의 가중치

    for start in range(N):
        visited = set([start])
        result = bellman_ford(N, edges, start)
        if visited == set(range(N)):
            break
        if result == "YES":
            break

    print(result)