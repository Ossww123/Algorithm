N = int(input())

# 행성들의 좌표를 저장
planets = []

for i in range(N):
    x, y, z = map(int, input().split())
    planets.append((x, y, z, i))
    
# 인접한 좌표끼리 간선 만들기
edges = []
for j in range(3):
    planets.sort(key=lambda k: k[j])
    for i in range(N - 1):
        u, i1 = planets[i][j], planets[i][3]
        v, i2 = planets[i + 1][j], planets[i + 1][3]

        edges.append((i1, i2, abs(u - v)))

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
