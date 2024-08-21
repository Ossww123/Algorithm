N = int(input())

# 행성들의 x, y, z 좌표를 따로 저장
x_planets = []
y_planets = []
z_planets = []

for i in range(N):
    x, y, z = map(int, input().split())

    x_planets.append((x, i))
    y_planets.append((y, i))
    z_planets.append((z, i))

# 인접한 행성들을 알기 위해 정렬
x_planets.sort()
y_planets.sort()
z_planets.sort()

# 인접한 좌표끼리 간선 만들기
edges = []
for i in range(N - 1):
    x1, ix1 = x_planets[i]
    x2, ix2 = x_planets[i + 1]

    y1, iy1 = y_planets[i]
    y2, iy2 = y_planets[i + 1]

    z1, iz1 = z_planets[i]
    z2, iz2 = z_planets[i + 1]

    edges.append((ix1, ix2, abs(x2 - x1)))
    edges.append((iy1, iy2, abs(y2 - y1)))
    edges.append((iz1, iz2, abs(z2 - z1)))


# 크루스칼 알고리즘
edges.sort(key=lambda k: k[2])

# 유니온 파인드
parent = list(range(N))

def find(x):
    if parent[x] != x:
        parent[x] = find(parent[x])
    return parent[x]


result = 0
for u, v, w in edges:
    root_u, root_v = find(u), find(v)
    if root_u != root_v:
        parent[root_u] = root_v
        result += w
        N -= 1
        if N == 1:
            break

print(result)
