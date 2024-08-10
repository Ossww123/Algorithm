from collections import deque

N, M = map(int, input().split())

singers = [0 for _ in range(N+1)]

edges = []
for _ in range(M):
    lst = list(map(int, input().split()))
    for i in range(1, len(lst)-1):
        edges.append((lst[i], lst[i+1]))

for start, end in edges:
    singers[end] += 1

que = deque([])

for idx in range(1, N+1):
    if singers[idx] == 0:
        que.append(idx)

result = []

for i in range(N):
    if not que:
        result = []
        break
    start = que.popleft()
    result.append(start)
    for s, e in edges:
        if s == start:
            singers[e] -= 1
            if singers[e] == 0:
                que.append(e)

if result:
    for i in range(N):
        print(result[i])
else:
    print(0)