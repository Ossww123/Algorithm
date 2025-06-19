a = int(input())
b = list(map(int,input().split()))

c = 0
for i in b:
    c += i
if c > 0:
    print("Right")
elif c == 0:
    print("Stay")
else:
    print("Left")