a1, b1, c1 = map(int, input().split())
a = 3*a1 + 20*b1+120*c1
a2, b2, c2 = map(int, input().split())
b = 3*a2 + 20*b2+120*c2

if a > b:
    print("Max")
elif a==b:
    print("Draw")
else:
    print("Mel")