N = int(input())

for i in range(1, N+1):
    a, b = map(int,input().split())
    if a < b:
        print("NO BRAINS")
    else:
        print("MMM BRAINS")