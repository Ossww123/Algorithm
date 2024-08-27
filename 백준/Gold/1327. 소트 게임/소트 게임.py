from collections import deque
import itertools

def list_to_tuple(lst):
    return tuple(lst)

def tuple_to_list(tup):
    return list(tup)

N, K = map(int, input().split())
lst = tuple(map(int, input().split()))

target = tuple(range(1, N+1))
visited = set([lst])
que = deque([(lst, 0)])

result = -1

if lst == target:
    result = 0
else:
    while que:
        start, cnt = que.popleft()
        
        for i in range(N-K+1):
            new_lst = start[:i] + start[i+K-1:i-1 if i > 0 else None:-1] + start[i+K:]
            
            if new_lst not in visited:
                visited.add(new_lst)
                if new_lst == target:
                    result = cnt + 1
                    que.clear()
                    break
                que.append((new_lst, cnt+1))

print(result)