def matrix_multiply(A, B):
    return [
        [
            (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % 1000000007,
            (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % 1000000007
        ],
        [
            (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % 1000000007,
            (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % 1000000007
        ]
    ]

def matrix_power(matrix, n):
    result = [[1, 0], [0, 1]]  # Identity matrix
    base = matrix

    while n > 0:
        if n % 2 == 1:
            result = matrix_multiply(result, base)
        base = matrix_multiply(base, base)
        n //= 2

    return result

def fibonacci(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1

    F = [[1, 1], [1, 0]]
    result = matrix_power(F, n-1)

    return result[0][0]

n = int(input())
print(fibonacci(n))
