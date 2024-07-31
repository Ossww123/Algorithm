dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
H, W = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(H)]

max_value = 0
for y in range(H):
    for x in range(W):
        value = matrix[y][x]

        for dy1, dx1 in dirs:
            ny1 = y + dy1
            nx1 = x + dx1
            if ny1 < 0 or ny1 >= H or nx1 < 0 or nx1 >= W:
                continue
            value += matrix[ny1][nx1]

            for dy2, dx2 in dirs:
                if dy2 == -dy1 and dx2 == -dx1:
                    continue
                ny2 = ny1 + dy2
                nx2 = nx1 + dx2
                if ny2 < 0 or ny2 >= H or nx2 < 0 or nx2 >= W:
                    continue
                value += matrix[ny2][nx2]

                for dy3, dx3 in dirs:
                    if dy3 == -dy2 and dx3 == -dx2:
                        continue
                    ny3 = ny2 + dy3
                    nx3 = nx2 + dx3
                    if ny3 < 0 or ny3 >= H or nx3 < 0 or nx3 >= W:
                        continue
                    value += matrix[ny3][nx3]
                    
                    max_value = max(max_value, value)
                    value -= matrix[ny3][nx3]

                if dy1 == dy2 and dx1 == dx2:
                    for dy3, dx3 in dirs:
                        if dy3 == -dy2 and dx3 == -dx2:
                            continue
                        if dy3 == dy2 and dx3 == dx2:
                            continue
                        ny3 = ny1 + dy3
                        nx3 = nx1 + dx3
                        if ny3 < 0 or ny3 >= H or nx3 < 0 or nx3 >= W:
                            continue
                        value += matrix[ny3][nx3]

                        max_value = max(max_value, value)
                        value -= matrix[ny3][nx3]

                value -= matrix[ny2][nx2]

            value -= matrix[ny1][nx1]

print(max_value)


