# import heapq
# import sys
#
# T = int(input())
#
# for tc in range(T):
#     k = int(input())
#     heap_lst = []
#     for _ in range(k):
#         cal, num = map(str, sys.stdin.readline().rstrip().split())
#         num = int(num)
#         if cal == 'I':
#             heapq.heappush(heap_lst, num)
#         elif cal == 'D':
#             if num == -1:
#                 if heap_lst:
#                     heapq.heappop(heap_lst)
#             elif num == 1:
#                 max_heap = []
#                 if heap_lst:
#                     for value in heap_lst:
#                         heapq.heappush(max_heap, -value)
#                     heap_lst = []
#                     heapq.heappop(max_heap)
#                     for value in max_heap:
#                         heapq.heappush(heap_lst, -value)
#     if heap_lst:
#         print(max(heap_lst), min(heap_lst))
#     else:
#         print('EMPTY')


import heapq
import sys
index = 1

T = int(input())

for tc in range(T):
    k = int(input())
    index += 1

    min_heap = []
    max_heap = []
    element_count = {}
    for _ in range(k):
        cal, num = map(str, sys.stdin.readline().rstrip().split())
        num = int(num)
        index += 1

        if cal == 'I':
            # Insert into both heaps
            heapq.heappush(min_heap, num)
            heapq.heappush(max_heap, -num)
            # Track the count of each element
            if num in element_count:
                element_count[num] += 1
            else:
                element_count[num] = 1
        elif cal == 'D':
            if num == -1:
                # Remove from min-heap
                while min_heap and element_count.get(min_heap[0], 0) == 0:
                    heapq.heappop(min_heap)
                if min_heap:
                    min_val = heapq.heappop(min_heap)
                    element_count[min_val] -= 1
            elif num == 1:
                # Remove from max-heap
                while max_heap and element_count.get(-max_heap[0], 0) == 0:
                    heapq.heappop(max_heap)
                if max_heap:
                    max_val = -heapq.heappop(max_heap)
                    element_count[max_val] -= 1

    while min_heap and element_count.get(min_heap[0], 0) == 0:
        heapq.heappop(min_heap)
    while max_heap and element_count.get(-max_heap[0], 0) == 0:
        heapq.heappop(max_heap)

    if min_heap:
        print(-max_heap[0], min_heap[0])
    else:
        print('EMPTY')

