def power(value, number, mod):
    if number == 0:
        return 1
    half = power(value, number // 2, mod)
    half = (half * half) % mod
    if number % 2 != 0:
        half = (half * value) % mod
    return half

A, B, C = map(int, input().split())
print(power(A, B, C))
