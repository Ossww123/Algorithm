n = int(input())
a = list(map(int, input().split()))

b = 0
for i in a:
    if i % 2 == 0:
        b += 1
    else:
        b -= 1
if b > 0:
    print("Happy")
else:
    print("Sad")