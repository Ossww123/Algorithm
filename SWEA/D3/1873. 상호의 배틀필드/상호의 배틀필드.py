def go_up(matrix, tank_y, tank_x):
    if (tank_y-1) >= 0 and matrix[tank_y-1][tank_x] == '.':
        matrix[tank_y][tank_x] = '.'
        matrix[tank_y-1][tank_x] = '^'
        return matrix, tank_y - 1, tank_x
    else:
        matrix[tank_y][tank_x] = '^'
        return matrix, tank_y, tank_x


def go_down(matrix, tank_y, tank_x):
    if (tank_y+1) < H and matrix[tank_y+1][tank_x] == '.':
        matrix[tank_y][tank_x] = '.'
        matrix[tank_y+1][tank_x] = 'v'
        return matrix, tank_y + 1, tank_x
    else:
        matrix[tank_y][tank_x] = 'v'
        return matrix, tank_y, tank_x

def go_right(matrix, tank_y, tank_x):
    if (tank_x+1) < W and matrix[tank_y][tank_x+1] == '.':
        matrix[tank_y][tank_x] = '.'
        matrix[tank_y][tank_x+1] = '>'
        return matrix, tank_y, tank_x + 1
    else:
        matrix[tank_y][tank_x] = '>'
        return matrix, tank_y, tank_x

def go_left(matrix, tank_y, tank_x):
    if (tank_x-1) >= 0 and matrix[tank_y][tank_x-1] == '.':
        matrix[tank_y][tank_x] = '.'
        matrix[tank_y][tank_x-1] = '<'
        return matrix, tank_y, tank_x - 1
    else:
        matrix[tank_y][tank_x] = '<'
        return matrix, tank_y, tank_x

def shoot(matrix, tank_y, tank_x):
    if matrix[tank_y][tank_x] == '^':
        if tank_y == 0:
            return matrix, tank_y, tank_x
        else:
            cannon = [tank_y - 1, tank_x]
            while cannon[0] >= 0:
                if matrix[cannon[0]][cannon[1]] == '*':
                    matrix[cannon[0]][cannon[1]] = '.'
                    return matrix, tank_y, tank_x
                elif matrix[cannon[0]][cannon[1]] == '#':
                    return matrix, tank_y, tank_x
                cannon[0] -= 1
            return matrix, tank_y, tank_x

    if matrix[tank_y][tank_x] == 'v':
        if tank_y == H-1:
            return matrix, tank_y, tank_x
        else:
            cannon = [tank_y + 1, tank_x]
            while cannon[0] < H:
                if matrix[cannon[0]][cannon[1]] == '*':
                    matrix[cannon[0]][cannon[1]] = '.'
                    return matrix, tank_y, tank_x
                elif matrix[cannon[0]][cannon[1]] == '#':
                    return matrix, tank_y, tank_x
                cannon[0] += 1
            return matrix, tank_y, tank_x

    if matrix[tank_y][tank_x] == '>':
        if tank_x == W-1:
            return matrix, tank_y, tank_x
        else:
            cannon = [tank_y, tank_x + 1]
            while cannon[1] < W:
                if matrix[cannon[0]][cannon[1]] == '*':
                    matrix[cannon[0]][cannon[1]] = '.'
                    return matrix, tank_y, tank_x
                elif matrix[cannon[0]][cannon[1]] == '#':
                    return matrix, tank_y, tank_x
                cannon[1] += 1
            return matrix, tank_y, tank_x

    if matrix[tank_y][tank_x] == '<':
        if tank_x == 0:
            return matrix, tank_y, tank_x
        else:
            cannon = [tank_y, tank_x - 1]
            while cannon[1] >= 0:
                if matrix[cannon[0]][cannon[1]] == '*':
                    matrix[cannon[0]][cannon[1]] = '.'
                    return matrix, tank_y, tank_x
                elif matrix[cannon[0]][cannon[1]] == '#':
                    return matrix, tank_y, tank_x
                cannon[1] -= 1
            return matrix, tank_y, tank_x

T = int(input())
for tc in range(1, T+1):
    H, W = map(int, input().split())
    matrix = []

    for _ in range(H):
        row = list(input())
        matrix.append(row)

    for y in range(H):
        for x in range(W):
            if matrix[y][x] in ['^', 'v', '<', '>']:
                tank_y = y
                tank_x = x
                break

    N = int(input())
    commands = list(input())

    for command in commands:
        if command == 'U':
            matrix, tank_y, tank_x = go_up(matrix, tank_y, tank_x)
        elif command == 'D':
            matrix, tank_y, tank_x = go_down(matrix, tank_y, tank_x)
        elif command == 'R':
            matrix, tank_y, tank_x = go_right(matrix, tank_y, tank_x)
        elif command == 'L':
            matrix, tank_y, tank_x = go_left(matrix, tank_y, tank_x)
        elif command == 'S':
            matrix, tank_y, tank_x = shoot(matrix, tank_y, tank_x)

    for y in range(H):
        if y == 0:
            print(f"#{tc} {''.join(map(str, matrix[y]))}")
        else:
            print(f"{''.join(map(str, matrix[y]))}")
