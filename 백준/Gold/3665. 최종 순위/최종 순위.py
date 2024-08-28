from collections import deque

def topological_sort(n, lst, m, changes):
    adj = [[] for _ in range(n+1)]
    indegree = [0] * (n+1)

    # 이전 순위에 따른 그래프 구성
    for i in range(n-1):
        for j in range(i+1, n):
            adj[lst[i]].append(lst[j])
            indegree[lst[j]] += 1

    # 순위 변경 적용
    for a, b in changes:
        if b in adj[a]:
            adj[a].remove(b)
            adj[b].append(a)
            indegree[b] -= 1
            indegree[a] += 1
        else:
            adj[b].remove(a)
            adj[a].append(b)
            indegree[a] -= 1
            indegree[b] += 1

    que = deque()
    for i in range(1, n+1):
        if indegree[i] == 0:
            que.append(i)

    result = []
    for i in range(n):
        if not que:
            return "IMPOSSIBLE"  # 사이클 존재

        if len(que) > 1:
            return "?"  # 확실한 순위를 결정할 수 없음

        curr = que.popleft()
        result.append(curr)

        for next_node in adj[curr]:
            indegree[next_node] -= 1
            if indegree[next_node] == 0:
                que.append(next_node)

    return " ".join(map(str, result))

T = int(input())

for _ in range(T):
    n = int(input())
    lst = list(map(int, input().split()))
    m = int(input())
    changes = [tuple(map(int, input().split())) for _ in range(m)]

    print(topological_sort(n, lst, m, changes))