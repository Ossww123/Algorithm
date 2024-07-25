def quadrant(N, y, x):
    length = 2 ** N
    if y < length // 2 and x < length // 2:
        return 0, y, x
    elif y < length // 2 and x >= length // 2:
        return 1, y, x - length // 2
    elif y >= length // 2 and x < length // 2:
        return 2, y - length // 2, x
    else:
        return 3, y - length // 2, x - length // 2

N, y, x = map(int, input().split())
result = 0
while N > 0:
    quad, y, x = quadrant(N, y, x)
    result += quad * 4 ** (N-1)
    N -= 1

print(result)