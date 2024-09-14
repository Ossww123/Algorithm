from collections import deque, defaultdict

N = int(input())
edges = [[] for _ in range(N)]
for _ in range(N - 1):
    u, v = map(lambda x: int(x) - 1, input().split())
    edges[u].append(v)
    edges[v].append(u)

current = list(map(int, input().split()))
car_num = 0
for i in current:
    if i == 1:
        car_num += 1

que = deque([0])
distance = [0] * N
distance[0] = 1


cars = []

while que:
    start = que.popleft()
    if current[start] == 1:
        a = len(cars)
        cars.append(car_num - a - 1 + distance[start])
        
    for node in edges[start]:
        if distance[node]:
            continue
        distance[node] = distance[start] + 1
        que.append(node)

print(max(cars))