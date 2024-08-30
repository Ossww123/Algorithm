# find : 부모찾기
def find(parent, x):
    if parent[x] != x:
        parent[x] = find(parent, parent[x])
    return parent[x]

# union : 합치기
def union(parent, rank, x, y):
    rootX = find(parent, x)
    rootY = find(parent, y)

    # x, y의 루트가 다르면 == x, y가 다른 컴포넌트면
    if rootX != rootY:
        if rank[rootX] > rank[rootY]:
            parent[rootY] = rootX
        elif rank[rootX] < rank[rootY]:
            parent[rootX] = rootY
            
        else:
            parent[rootY] = rootX
            rank[rootX] += 1


def count_components(N, edges):
    parent = list(range(N + 1))  # 각 번호의 루트를 자기자신으로 초기화
    rank = [0] * (N + 1)

    for u, v in edges:
        union(parent, rank, u, v)

    # 루트의 개수 == 컴포넌트의 개수
    unique_roots = len(set(find(parent, i) for i in range(1, N + 1)))
    return unique_roots


T = int(input())
for tc in range(1, T+1):
    N, M = map(int, input().split())
    edges = [tuple(map(int, input().split())) for _ in range(M)]
    
    print(f'#{tc} {count_components(N, edges)}')
