N = int(input())
cost_RGB = [list(map(int, input().split())) for _ in range(N)]
all_cost = [[0, 0, 0] for _ in range(N)]

INF = 1e17
result = []

all_cost[0] = [cost_RGB[0][0], INF, INF]

# 최종 집에서 R, G, B를 선택했을 경우를 각각 기록해서 DP알고리즘 사용
for i in range(1, N):
    for j in range(3):
        if j == 0:
            all_cost[i][0] = min(all_cost[i - 1][1], all_cost[i - 1][2]) + cost_RGB[i][0]
        elif j == 1:
            all_cost[i][1] = min(all_cost[i - 1][0], all_cost[i - 1][2]) + cost_RGB[i][1]
        elif j == 2:
            all_cost[i][2] = min(all_cost[i - 1][0], all_cost[i - 1][1]) + cost_RGB[i][2]


result.append(all_cost[N - 1][1])
result.append(all_cost[N - 1][2])

all_cost[0] = [INF, cost_RGB[0][1], INF]

# 최종 집에서 R, G, B를 선택했을 경우를 각각 기록해서 DP알고리즘 사용
for i in range(1, N):
    for j in range(3):
        if j == 0:
            all_cost[i][0] = min(all_cost[i - 1][1], all_cost[i - 1][2]) + cost_RGB[i][0]
        elif j == 1:
            all_cost[i][1] = min(all_cost[i - 1][0], all_cost[i - 1][2]) + cost_RGB[i][1]
        elif j == 2:
            all_cost[i][2] = min(all_cost[i - 1][0], all_cost[i - 1][1]) + cost_RGB[i][2]


result.append(all_cost[N - 1][0])
result.append(all_cost[N - 1][2])

all_cost[0] = [INF, INF, cost_RGB[0][2]]

# 최종 집에서 R, G, B를 선택했을 경우를 각각 기록해서 DP알고리즘 사용
for i in range(1, N):
    for j in range(3):
        if j == 0:
            all_cost[i][0] = min(all_cost[i - 1][1], all_cost[i - 1][2]) + cost_RGB[i][0]
        elif j == 1:
            all_cost[i][1] = min(all_cost[i - 1][0], all_cost[i - 1][2]) + cost_RGB[i][1]
        elif j == 2:
            all_cost[i][2] = min(all_cost[i - 1][0], all_cost[i - 1][1]) + cost_RGB[i][2]


result.append(all_cost[N - 1][0])
result.append(all_cost[N - 1][1])

print(min(result))
