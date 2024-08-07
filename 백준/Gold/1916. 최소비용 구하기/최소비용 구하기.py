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
min_costs = [float('inf')] * (N+1)
min_costs[from_city] = 0
visited = [False] * (N+1)

# DFS는 아니고.. 스택 굳이 안써도 될거같은데
stk = [from_city]
while stk:

    # 방문한 도시는 visited = True
    start_city = stk.pop()
    visited[start_city] = True

    # start_city에서 cost를 더한 값과 원래 가지고 있던 값중 작은 값을 min_costs에 입력!
    if start_city in bus_costs:
        for goal, goal_cost in bus_costs[start_city]:
            min_costs[goal] = min(min_costs[goal], min_costs[start_city] + goal_cost)

    # 방문하지 않은 도시 중에서 최소 비용을 가진 도시를 골라봐요!
    min_index = -1
    min_value = float('inf')
    for index, (visited_status, cost) in enumerate(zip(visited, min_costs)):
        if not visited_status and cost < min_value:
            min_value = cost
            min_index = index

    # 최소 비용의 도시를 스택에 push!
    if min_index != -1:
        stk.append(min_index)

print(min_costs[to_city])