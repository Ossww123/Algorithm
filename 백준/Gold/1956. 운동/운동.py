V, E = map(int, input().split())

# inf 기본값을 가진 N * N 2차원 리스트 생성
layer = [[float('inf')] * (V+1) for _ in range(V+1)]

# i번 정점에서 i번 정점으로 가는 데 드는 비용 0
# for i in range(1, V+1):
#     layer[i][i] = 0

# layer[y][x] 에 비용 cost 입력, 똑같지만 비용이 다른 버스 주의! 말은 끝까지 들으세요.
for _ in range(E):
    a, b, c = map(int, input().split())
    layer[a][b] = c

# 플로이드 와샬 알고리즘
for k in range(V+1):
    for y in range(V+1):
        for x in range(V+1):
            layer[y][x] = min(layer[y][x], layer[y][k] + layer[k][x])

temp = 1e18
result = -1
for i in range(1, V+1):
    if layer[i][i] < 1e17:
        if layer[i][i] < temp:
            result = i
            temp = min(temp, layer[i][i])


if result == -1:
    print(-1)
else:
    print(temp)