num_cities = int(input())
num_buses = int(input())

# inf 기본값을 가진 N * N 2차원 리스트 생성
layer = [[float('inf')] * num_cities for _ in range(num_cities)]

# i번 정점에서 i번 정점으로 가는 데 드는 비용 0
for i in range(num_cities):
    layer[i][i] = 0

# layer[y][x] 에 비용 cost 입력, 똑같지만 비용이 다른 버스 주의! 말은 끝까지 들으세요.
for bus in range(num_buses):
    from_city, to_city, cost = map(int, input().split())
    if layer[from_city - 1][to_city - 1] > cost:
        layer[from_city - 1][to_city - 1] = cost

# 플로이드 와샬 알고리즘
for k in range(num_cities):
    for y in range(num_cities):
        for x in range(num_cities):
            layer[y][x] = min(layer[y][x], layer[y][k] + layer[k][x])

# i에서 j로 갈 수 없는 경우 0을 출력합니다. 말은 끝까지 들으세요.
for y in range(num_cities):
    for x in range(num_cities):
        if layer[y][x] == float('inf'):
            layer[y][x] = 0

for i in range(num_cities):
    print(' '.join(map(str, layer[i])))