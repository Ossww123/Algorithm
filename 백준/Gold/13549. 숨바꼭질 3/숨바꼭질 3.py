from collections import deque

N, K = map(int, input().split())
visited = [-1] * 100001
que = deque()

def teleport(a, time):
    if a != 0:
        while a <= 100000:
            if visited[a] == -1 or time < visited[a]:
                que.append(a)
                visited[a] = time
            a *= 2

que.append(N)
visited[N] = 0

while que:
    start = que.popleft()
    teleport(start, visited[start])

    for i in range(2):
        if i == 0 and start >= 1 and visited[start-1] == -1:
            que.append(start-1)
            visited[start-1] = visited[start] + 1
        elif i == 1 and start < 100000 and visited[start+1] == -1:
            que.append(start+1)
            visited[start+1] = visited[start] + 1

print(visited[K])
