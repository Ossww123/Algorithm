from collections import deque

N, M, K, X = map(int, input().split())

visited=[-1]*(N+1)
city=[[] for _ in range(N+1)]
for _ in range(M):
    a, b = map(int, input().split())
    city[a].append(b)

que = deque()
que.append(X)
visited[X] = 0
flag = True
A = []

while que:
    start = que.popleft()

    if visited[start] > K:
        break

    if city[start]:
        for ct in city[start]:
            if visited[ct] == -1:
                visited[ct] = visited[start] + 1

                if visited[ct] == K:
                    A.append(ct)
                    flag = False
                que.append(ct)

if A:
    A.sort()
    for i in A:
        print(i)

if flag:
    print(-1)