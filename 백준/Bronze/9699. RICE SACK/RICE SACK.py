T = int(input())

for tc in range(1,T+1):
    result = max(map(int,input().split()))
    print(f"Case #{tc}: {result}")