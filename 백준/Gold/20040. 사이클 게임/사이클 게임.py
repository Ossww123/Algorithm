# 노드의 수 N, 간선의 수 M
N, M = map(int, input().split())

# 간선 입력 받기
lines = []
for _ in range(M):
    lines.append(tuple(map(int, input().split())))

# 모든 노드의 루트를 자기자신으로 초기화 (0부터 N-1까지)
parent = list(range(N))
rank = [0] * N

# 유니온 파인드의 find (경로 압축 포함)
def find(x):
    if parent[x] != x:
        parent[x] = find(parent[x])  # 경로 압축
    return parent[x]

# 유니온 파인드의 union (랭크 기반)
def union(x, y):
    root_x = find(x)
    root_y = find(y)
    if root_x != root_y:
        if rank[root_x] > rank[root_y]:
            parent[root_y] = root_x
        elif rank[root_x] < rank[root_y]:
            parent[root_x] = root_y
        else:
            parent[root_y] = root_x
            rank[root_x] += 1
        return True
    return False

result = 0
for u, v in lines:
    result += 1
    # 1-based 인덱스에서 0-based 인덱스로 변환
    u -= 1
    v -= 1
    if not union(u, v):
        print(result)  # 사이클이 형성되면 현재까지의 간선 수 출력
        break
else:
    print(0)  # 모든 간선을 확인했는데 사이클이 없으면 0 출력
