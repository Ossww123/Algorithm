N = int(input())
M = int(input())

# 입력 받는 코드, bus_costs[출발도시번호] = (도착도시번호, 버스비용)
bus_costs = {}
for _ in range(M):
    st, ed, cost = map(int, input().split())
    if st not in bus_costs:
        bus_costs[st] = []
    bus_costs[st].append((ed, cost))

from_city, to_city = map(int, input().split())

# 데이크스트라 알고리즘 사용을 위한 리스트
min_costs = [float('inf')] * (N + 1)
min_costs[from_city] = 0
visited = [False] * (N + 1)

# 경로 추적을 위한 리스트
prev_city = [-1] * (N + 1)

# 우선순위 큐를 사용하여 효율성 향상
import heapq

pq = [(0, from_city)]

while pq:
    # 현재 최소 비용을 가진 도시 선택
    current_cost, current_city = heapq.heappop(pq)

    # 이미 방문한 도시라면 스킵
    if visited[current_city]:
        continue

    # 방문 처리
    visited[current_city] = True

    # 목적지에 도달했다면 종료
    if current_city == to_city:
        break

    # 인접한 도시들에 대해 최소 비용 갱신
    if current_city in bus_costs:
        for next_city, next_cost in bus_costs[current_city]:
            new_cost = current_cost + next_cost
            if new_cost < min_costs[next_city]:
                min_costs[next_city] = new_cost
                prev_city[next_city] = current_city
                heapq.heappush(pq, (new_cost, next_city))

# 최소 비용 출력
print(min_costs[to_city])

# 경로 역추적
path = []
current = to_city
while current != -1:
    path.append(current)
    current = prev_city[current]
path.reverse()

# 경로 출력
print(len(path))
print(*path)