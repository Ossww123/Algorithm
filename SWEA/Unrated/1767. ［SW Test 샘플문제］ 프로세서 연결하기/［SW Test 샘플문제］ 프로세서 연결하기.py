DIRS = [(-1, 0), (1, 0), (0, -1), (0, 1)]


def connect_line(cell, dir):  # 0상 1하 2좌 3우
    sY, sX = cell[0] + DIRS[dir][0], cell[1] + DIRS[dir][1]
    result = set()
    while 0 <= sY < N and 0 <= sX < N:
        if (sY, sX) in visited:
            return set()
        result.add((sY, sX))
        sY, sX = sY + DIRS[dir][0], sX + DIRS[dir][1]

    return result


def solve(cnt, total, connected_cores):
    global min_value
    global visited
    global max_core

    if max_core > connected_cores + (len(cells) - cnt):
        return

    if cnt == len(cells):
        if max_core < connected_cores:
            min_value = total
            max_core = connected_cores

        elif max_core == connected_cores:
            min_value = min(min_value, total)

        return

    for dir in range(4):
        lines = connect_line(cells[cnt], dir)

        if visited & lines:
            continue

        if lines:
            visited |= lines
            solve(cnt + 1, total + len(lines), connected_cores + 1)
            visited -= lines
        else:
            solve(cnt + 1, total + len(lines), connected_cores)


T = int(input())
for tc in range(1, T + 1):
    N = int(input())
    MEXINOS = [list(map(int, input().split())) for _ in range(N)]

    cells = []
    visited = set()
    for i in range(N):
        for j in range(N):
            if MEXINOS[i][j]:
                visited.add((i, j))
                if i not in [0, N - 1] and j not in [0, N - 1]:
                    cells.append((i, j))

    min_value = 0xFFFFFFFF
    max_core = -1
    solve(0, 0, len(visited))
    print(f'#{tc} {min_value}')
