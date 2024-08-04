T = int(input())

for tc in range(1, T+1):
    N = int(input())
    result = [0] * 5
    while N % 2 == 0:
        N = N // 2
        result[0] += 1
    while N % 3 == 0:
        N = N // 3
        result[1] += 1
    while N % 5 == 0:
        N = N // 5
        result[2] += 1
    while N % 7 == 0:
        N = N // 7
        result[3] += 1
    while N % 11 == 0:
        N = N // 11
        result[4] += 1

    print(f"#{tc} {' '.join(map(str, result))}")