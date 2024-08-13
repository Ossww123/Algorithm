import heapq

N = int(input())

# 첫 행 리스트를 받아 최소 힙으로 변경합니다.
lst = list(map(int, input().split()))
heapq.heapify(lst)

# 다음 행의 N개 원소를 넣고 N번 pop합니다.
for _ in range(N-1):
    
    # 다음 행의 원소를 받습니다.
    next_lst = list(map(int, input().split()))
    
    # 그 원소들을 최소힙에 넣습니다.
    for i in next_lst:
        heapq.heappush(lst, i)
    
    # root부분, 즉 최소값을 N번 pop합니다.
    for _ in range(N):
        heapq.heappop(lst)

# 마지막에 남은 최소힙에서 최소값을 얻으면 답이 됩니다.
print(heapq.heappop(lst))