N, B = map(int, input().split())

# 행렬곱
def multiple_matrix(matrix1, matrix2):
    result = [[0]*N for _ in range(N)]
    for y in range(N):
        for x in range(N):
            for i in range(N):
                result[y][x] = (result[y][x] + matrix1[y][i] * matrix2[i][x]) % 1000

    return result

# 분할정복
def div_and_conq(matrix, B):
    if B == 1:
        for y in range(N):
            for x in range(N):
                matrix[y][x] = matrix[y][x] % 1000
        return matrix

    # B가 짝수면 그냥 거듭제곱, 홀수면 거듭제곱 * matrix
    if B % 2 == 0:
        half = div_and_conq(matrix, B // 2)
        return multiple_matrix(half, half)
    else:
        half = div_and_conq(matrix, B // 2)
        temp = multiple_matrix(half, half)
        return multiple_matrix(temp, matrix)

arr = [list(map(int, input().split())) for _ in range(N)]

arr = div_and_conq(arr, B)

# 출력
for row in arr:
    print(*row)