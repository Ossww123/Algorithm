from collections import deque

N = int(input())
M = int(input())

indegree = [0] * (N+1)

adj = [[] for _ in range(N+1)]

for _ in range(M):
    X, Y, K = map(int, input().split())
    indegree[X] += 1
    adj[Y].append((X, K))

que = deque()
basic_parts = [[0] * (N+1) for _ in range(N+1)]

basic = []
for i in range(1, N+1):
    if indegree[i] == 0:
        que.append(i)
        basic_parts[i][i] = 1
        basic.append(i)




for i in range(N):
    curr = que.popleft()

    for next_node, needed_num in adj[curr]:
        indegree[next_node] -= 1

        for j in range(1, N+1):
            basic_parts[next_node][j] += basic_parts[curr][j] * needed_num

        if indegree[next_node] == 0:
            que.append(next_node)

for i in basic:
    print(f'{i} {basic_parts[N][i]}')