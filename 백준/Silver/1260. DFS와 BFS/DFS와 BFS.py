# queue를 위한 deque, key가 없을 때 기본값을 출력하도록 defaultdict 호출
from collections import deque, defaultdict

# 정점(노드)의 개수 N, 간선의 개수 M, 시작 정점(노드) V를 입력으로 받습니다.
N, M, V = map(int, input().split())

# edges에 간선을 추가합니다. 양방향이므로 반대방향도 추가합니다.
edges = defaultdict(list)
for _ in range(M):
    a, b = map(int, input().split())
    if a in edges:
        edges[a].append(b)
    else:
        edges[a] = [b]
    if b in edges:
        edges[b].append(a)
    else:
        edges[b] = [a]

# DFS를 시행합니다.
visited = [False for _ in range(N)]
stk = [V]
dfs_list = []
start_node = V

while stk:
    start_node = stk.pop()
    if not visited[start_node - 1]:
        visited[start_node - 1] = True
        dfs_list.append(start_node)

        for edge in sorted(edges[start_node],reverse=True): # 숫자가 작은 노드부터!
            if visited[edge-1]:
                continue
            else:
                stk.append(edge)

# BFS를 시행합니다.
visited = [False for _ in range(N)]
que = deque([V])
bfs_list = []
visited[V-1] = True

while que:
    start_node = que.popleft()
    bfs_list.append(start_node)

    for edge in sorted(edges[start_node]):
        if visited[edge-1]:
            continue
        else:
            visited[edge - 1] = True
            que.append(edge)

print(' '.join(map(str, dfs_list)))
print(' '.join(map(str, bfs_list)))