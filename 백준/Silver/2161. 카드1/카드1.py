from collections import deque

N = int(input())

que = deque([i for i in range(1, N+1)])

for _ in range(N):
    print(que.popleft())
    if que:
        que.append(que.popleft())