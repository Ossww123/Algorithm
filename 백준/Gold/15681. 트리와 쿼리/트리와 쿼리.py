def iterative_dfs(R, edges, N):
    dp = [1] * (N + 1)  # dp[i]는 노드 i를 루트로 하는 서브트리의 크기
    visited = [False] * (N + 1)
    stack = [(R, None)]  # (node, parent)

    order = []

    # 후위 순회 순서 구하기
    while stack:
        node, parent = stack.pop()
        order.append((node, parent))
        visited[node] = True
        for child in edges[node]:
            if not visited[child]:
                stack.append((child, node))

    # 후위 순서로 DP 배열 업데이트
    while order:
        node, parent = order.pop()
        if parent is not None:
            dp[parent] += dp[node]

    return dp


# 입력 받기
N, R, Q = map(int, input().split())
edges = [[] for _ in range(N + 1)]

for _ in range(N - 1):
    a, b = map(int, input().split())
    edges[a].append(b)
    edges[b].append(a)

# 서브트리 크기 계산
dp = iterative_dfs(R, edges, N)

# 질의 처리
for _ in range(Q):
    q = int(input())
    print(dp[q])
