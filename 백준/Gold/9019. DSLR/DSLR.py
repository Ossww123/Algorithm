from collections import deque

cals = ['D', 'S', 'L', 'R']
T = int(input())

for tc in range(T):
    reg = [''] * 10000
    start_num, end_num = map(int, input().split())
    queue = deque([start_num])

    while queue:
        start_x = queue.popleft()

        for cal in cals:
            if cal == 'D':
                nx = (start_x * 2) % 10000
            elif cal == 'S':
                nx = start_x - 1
                if nx == -1:
                    nx = 9999
            elif cal == 'L':
                nx = (start_x % 1000) * 10 + start_x // 1000
            elif cal == 'R':
                nx = (start_x % 10) * 1000 + start_x // 10

            if reg[nx] or nx == start_num:
                continue

            queue.append(nx)
            reg[nx] = reg[start_x] + cal
        if reg[end_num]:
            break
    print(reg[end_num])