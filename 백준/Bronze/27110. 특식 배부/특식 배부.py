n = int(input())
a, b, c = map(int, input().split())

total = 0
total += min(n, a)
total += min(n, b)
total += min(n, c)

print(total)