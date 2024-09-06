from collections import deque

DIRS = [(0, 1), (0, -1), (1, 0), (-1, 0)]


def BFS(permu):
    global result

    que = deque()
    que.append((permu[0]))
    visited = [permu[0]]

    while que:
        sy, sx = que.popleft()

        for dy, dx in DIRS:
            ny, nx = dy + sy, dx + sx

            if (ny, nx) in visited:
                continue

            if (ny, nx) in permu:
                visited.append((ny, nx))
                que.append((ny, nx))

    if len(visited) == 7:
        result += 1


def permutation(Y_cnt = 0, permu = [], idx = 0):
    if Y_cnt > 3:
        return

    if len(permu) == 7:
        BFS(permu)
        return

    if idx >= 25:
        return

    yy, xx = lst[idx]

    permu.append((yy, xx))
    if students[yy][xx] == 'Y':
        permutation(Y_cnt + 1, permu, idx + 1)
    else:
        permutation(Y_cnt, permu, idx + 1)
    permu.pop()

    permutation(Y_cnt, permu, idx + 1)




students = [list(input()) for _ in range(5)]
lst = [(y, x) for y in range(5) for x in range(5)]
result = 0

permutation()

print(result)