import heapq

T = int(input())
for _ in range(T):
    M = int(input())
    N = M // 10
    num_lst = []

    for _ in range(N+1):
        num_lst.extend(list(map(int, input().split())))

    max_heap = []
    min_heap = []
    mid_num = num_lst[0]
    print(M//2 + 1)

    if M == 1:
        print(mid_num)
    else:
        result = [num_lst[0]]
        for i in range(1, M):
            if i % 2 == 1:
                if num_lst[i] > mid_num:
                    heapq.heappush(max_heap, -mid_num)
                    heapq.heappush(min_heap, num_lst[i])
                else:
                    heapq.heappush(max_heap, -num_lst[i])
                    heapq.heappush(min_heap, mid_num)
            else:
                if num_lst[i] < -max_heap[0]:
                    heapq.heappush(max_heap, -num_lst[i])
                    mid_num = -heapq.heappop(max_heap)
                elif num_lst[i] > min_heap[0]:
                    heapq.heappush(min_heap, num_lst[i])
                    mid_num = heapq.heappop(min_heap)
                else:
                    mid_num = num_lst[i]
                result.append(mid_num)

        idx = 0
        for _ in range(len(result) // 10):
            print(*result[idx:idx + 10])
            idx += 10
        print(*result[idx:])

