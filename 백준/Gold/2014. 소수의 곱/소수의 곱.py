import heapq

K, N = map(int,input().split())

# 소수 리스트입니다.
lst = list(map(int, input().split()))

# 힙에 소수 리스트를 복사해옵니다.
heap = lst[:]

cnt = 0
before_num = 0

while True:
    # i번째로 작은 값을 빼냅니다.
    num = heapq.heappop(heap)

    # 이전에 뽑았던 값이라면 다시
    if num == before_num:
        continue
    before_num = num

    # N번째로 값을 뽑았을 때 스탑!
    cnt += 1
    if cnt == N:
        break

    # 힙에 i번째로 작은 값과 소수들의 곱을 추가합니다.
    for i in lst:
        if num < 1<<30:
            heapq.heappush(heap, num * i)


print(num)