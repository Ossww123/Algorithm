from pprint import pprint as pp

N, M = map(int, input().split())

# inf 기본값을 가진 N * N 2차원 리스트 생성
layer = [[float('inf')] * (N+1) for _ in range(N+1)]

# i번 정점에서 i번 정점으로 가는 데 드는 비용 0
# for i in range(1, V+1):
#     layer[i][i] = 0

# layer[y][x] 에 비용 cost 입력, 똑같지만 비용이 다른 버스 주의! 말은 끝까지 들으세요.
for _ in range(M):
    a, b = map(int, input().split())
    layer[a][b] = 1

# 플로이드 와샬 알고리즘
for k in range(N+1):
    for y in range(N+1):
        for x in range(N+1):
            layer[y][x] = min(layer[y][x], layer[y][k] + layer[k][x])

cnt = 0
for i in range(1, N+1):
    for j in range(1, N+1):
        if i == j:
            continue
        if layer[i][j] > 1e17 and layer[j][i] > 1e17:
            break
    else:
        cnt += 1
print(cnt)