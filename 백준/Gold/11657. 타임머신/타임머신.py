# 입력 받기
N, M = map(int, input().split())
INF = 1e18
edges = []
for _ in range(M):
    a, b, c = map(int, input().split())
    edges.append((a, b, c))

# 도시까지 걸리는 시간 리스트를 기본값을 무한대로 하고 만듭니다.
time = [INF] * (N+1)
time[1] = 0

# 음수사이클이 나올 경우를 기록할 플래그
minus_cycle = False

# 벨만포드 알고리즘, 총 N-1번 간선을 거쳤을 때의 최소 시간을 기록 
for i in range(N):
    for u, v, w in edges:
        if time[u] != INF and time[v] > time[u] + w:
            time[v] = time[u] + w
            
            # N번째에도 값이 바뀐다면 음수 사이클이 존재함을 의미
            if i == N - 1:
                minus_cycle = True

if minus_cycle:
    print(-1)
else:
    for i in range(2, N+1):
        if time[i] != INF:
            print(time[i])
        else:
            print(-1)