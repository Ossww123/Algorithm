E, S, M = map(int, input().split())
x = 1
while True:
    a = x % 15
    b = x % 28
    c = x % 19

    if a == 0:
        a = 15

    if b == 0:
        b = 28

    if c == 0:
        c = 19

    if a == E and b == S and c == M:
        break

    x += 1

print(x)