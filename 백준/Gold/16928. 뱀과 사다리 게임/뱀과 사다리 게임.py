from collections import deque

N, M = map(int, input().split())

# 한 점점에서 +1 ~ +6까지 갈 수 있다.
move = {}
for kan in range(1, 101):
    move[kan] = []
    for i in range(1, 7):
        if kan + i < 101:
            move[kan].append(kan+i)

# 사다리 혹은 뱀칸 판별을 위한 리스트
ladder_snake = []
for _ in range(N):
    a, b = map(int, input().split())
    ladder_snake.append(a)
    move[a] = [b]
for _ in range(M):
    a, b = map(int, input().split())
    ladder_snake.append(a)
    move[a] = [b]

queue = deque([1])
visited = [0] * 101
visited[1] = 1

# BFS 시행
while queue:
    start = queue.popleft()
    
    # 사다리 혹은 뱀칸이라면 강제 이동
    if start in ladder_snake:
        visited[move[start][0]] = visited[start]
        start = move[start][0]

    for m in move[start]:
        if not visited[m]:
            queue.append(m)
            visited[m] = visited[start] + 1

print(visited[100] - 1)