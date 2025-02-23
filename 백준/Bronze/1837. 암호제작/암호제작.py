P, K = map(int, input().split())
isGood = True
badNum = 0

for i in range(2, K):
    if P % i == 0:
        isGood = False
        badNum = i
        break

if isGood:
    print("GOOD")
else:
    print("BAD", badNum)