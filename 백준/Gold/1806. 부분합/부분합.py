N, S = map(int, input().split())
lst = list(map(int, input().split()))

# 투 포인터
L = R = 0

cumulative = 0
min_length = 1e17

while True:
    if cumulative >= S or R == N:
        cumulative -= lst[L]
        L += 1

    else:
        cumulative += lst[R]
        R += 1

    if cumulative >= S:
        min_length = min(min_length, R-L)

    if L == R == N:
        break

    # print(L, R, cumulative, min_length)

if min_length == 1e17:
    print(0)
else:
    print(min_length)