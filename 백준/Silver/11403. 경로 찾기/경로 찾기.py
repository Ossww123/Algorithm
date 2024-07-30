N = int(input())

layer = []
for _ in range(N):
    row = list(map(int, input().split()))
    layer.append(row)

for y in range(N):
    for x in range(N):
        if layer[y][x] == 0:
            layer[y][x] = float('inf')

for k in range(N):
    for y in range(N):
        for x in range(N):
            layer[y][x] = min(layer[y][x], layer[y][k] + layer[k][x])

for y in range(N):
    for x in range(N):
        if layer[y][x] == float('inf'):
            layer[y][x] = 0
        else:
            layer[y][x] = 1

for i in range(N):
    print(' '.join(map(str, layer[i])))