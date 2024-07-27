from collections import deque

N = int(input())
M = int(input())
S = input()

queue = deque([])
length = 0
result = 0

for ch in S:
    if not queue:
        if ch == 'I':
            queue.append(ch)
            length = 1
        continue
    if queue[0] == 'O':
        queue.popleft()
        length -= 1
    if queue[-1] == ch:
        queue = deque([])
        length = 0
        if ch == 'I':
            queue.append(ch)
            length = 1
    else:
        queue.append(ch)
        length += 1
        if length == (2 * N + 1) and queue[0] == 'I':
            result += 1
            length -= 1
            queue.popleft()

print(result)