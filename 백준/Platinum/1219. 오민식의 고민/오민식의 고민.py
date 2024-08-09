# 입력 받기, 쓰는 돈을 양수로, 버는 돈을 음수로 합니다.
N, start_city, end_city, M = map(int, input().split())
INF = 1e18

# 간선의 정보입니다.
edges = []
for _ in range(M):
    a, b, c = map(int, input().split())
    edges.append((a, b, c))

# 도시에서 벌어들이는 값입니다.
city_sales = list(map(int, input().split()))

# 돈 리스트를 기본값을 무한대로 하고 만듭니다. 시작 도시에서 버는 돈을 음수로 합니다.
cost = [INF] * N
cost[start_city] = -city_sales[start_city]

# 음수사이클(돈복사)이 나올 경우를 기록할 플래그
minus_cycle = False

# *추가: 음수 싸이클 확인용 변수
minus_cycle_nodes = []

# 벨만포드 알고리즘, 총 N-1번 간선을 거쳤을 때의 최소 비용(돈 최대로 버는 것)을 기록
for i in range(N):
    for u, v, w in edges:

        # 간선의 가중치에 도시에서 벌어들이는 값을 뺍니다.
        if cost[u] != INF and cost[v] > cost[u] + w - city_sales[v]:
            cost[v] = cost[u] + w - city_sales[v]

            # N번째에도 값이 바뀐다면 음수 사이클이 존재함을 의미
            if i == N - 1:
                minus_cycle = True

                # *추가: 음수 싸이클의 노드를 모두 가져온다.
                minus_cycle_nodes.append(v)

# *추가: 음수 싸이클에서 도착 도시 갈 수 있는지 체크
check_minus_to_end = False
if end_city in minus_cycle_nodes:
    check_minus_to_end = True
    
visited = [False] * N
for minus_cycle_node in minus_cycle_nodes:
    
    if not visited[minus_cycle_node]:
        stk = [minus_cycle_node]
    while stk and not check_minus_to_end:
        start_node = stk.pop()
        visited[start_node] = True
    
        for u, v, w in edges:
            if u == start_node and not visited[v]:
                if v == end_city:
                    check_minus_to_end = True
                    break
                stk.append(v)
    
    if check_minus_to_end:
        break


# 도착 도시에 도달할 수 없다면
if cost[end_city] == INF:
    print('gg')

else:
    # 음수싸이클이 존재한다면 (돈복사), *추가: 거기에서 도착도시를 갈 수 있다면!
    if check_minus_to_end:
        print('Gee')

    else:
        print(-cost[end_city])
