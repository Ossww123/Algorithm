import heapq

N = int(input())
lst = [int(input()) for _ in range(N)]

heapq.heapify(lst)

sum = 0
for _ in range(N-1):
    a = heapq.heappop(lst)
    b = heapq.heappop(lst)
    sum += (a+b)
    heapq.heappush(lst, a+b)

print(sum)