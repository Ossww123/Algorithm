def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

T = int(input())

for tc in range(T):
    M, N, x, y = map(int, input().split()) # 39999 2 39998 2
    L = lcm(M, N)       # 79998
    k = 0
    result = -1
    if M == x:
        x = 0
        k = 1
    if N == y: # True
        y = 0

    while k * M + x <= L:
        if (k * M + x) % N == y:
            result = k * M + x
            break
        k += 1

    print(result)