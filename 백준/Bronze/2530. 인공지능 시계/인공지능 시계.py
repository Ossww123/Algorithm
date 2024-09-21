H, M, S = map(int, input().split())
num = int(input())
num += S
newS = num % 60
newM = (M + (num // 60)) % 60
newH = (H + (M + (num // 60)) // 60) % 24

print(newH, newM, newS)
