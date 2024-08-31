F = [0, 1]
i = 1
while True:
    i += 1
    F.append((F[i - 1] + F[i - 2]) % 1000000)
    if F[i] == 1:
        if F[i - 1] == 0:
            break
n = int(input())
print(F[n % (i - 1)])
