N = int(input())
min_bag = [float('inf')] * 5001

min_bag[3] = 1
min_bag[5] = 1

for i in range(6, N+1):
    min_bag[i] = min(min_bag[i-3] + 1, min_bag[i-5] + 1)

if min_bag[N] == float('inf'):
    print(-1)
else:
    print(min_bag[N])
