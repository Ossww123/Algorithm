from collections import deque

A, B = map(int, input().split())

num_dict = {}
num_dict[A] = 1
que = deque([A])

# BFS로 탐색
while que:
    start = que.popleft()

    # *2를 하거나 뒤에 1을 붙이거나
    for i in range(2):
        if i == 0:
            value = start * 2
        elif i == 1:
            value = start * 10 + 1

        # B보다 작고 아직 값이 없다면
        if value <= B and not value in num_dict:
            num_dict[value] = num_dict[start] + 1
            que.append(value)

if B in num_dict:
    print(num_dict[B])
else:
    print(-1)