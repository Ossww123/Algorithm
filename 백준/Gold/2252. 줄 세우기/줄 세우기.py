from collections import deque

N, M = map(int, input().split())

students = [0 for i in range(N+1)]

edges = []
for _ in range(M):
    a, b = map(int, input().split())
    edges.append((a, b))

for start, end in edges:
    students[end] += 1

que = deque([])

for idx in range(1, N+1):
    if students[idx] == 0:
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
            students[e] -= 1
            if students[e] == 0:
                que.append(e)

print(*result)
