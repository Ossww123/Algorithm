from collections import deque

N, K = map(int,input().split())
needed_time = [-1]*100_001
needed_time[N] = 0

que = deque()
que.append(N)

cnt = 0
while que:
    start = que.popleft()
    if needed_time[K] != -1 and needed_time[start] >= needed_time[K]:
        continue

    if start + 1 <= 100_000 and (needed_time[start+1] == -1 or needed_time[start+1] == needed_time[start]+1):
        que.append(start+1)
        needed_time[start+1] = needed_time[start] + 1

        if start+1 == K:
            cnt += 1

    if start - 1 >= 0 and (needed_time[start-1] == -1 or needed_time[start-1] == needed_time[start]+1):
        que.append(start-1)
        needed_time[start-1] = needed_time[start] + 1

        if start-1 == K:
            cnt += 1

    if start * 2 <= 100_000 and (needed_time[start*2] == -1 or needed_time[start*2] == needed_time[start]+1):
        que.append(start*2)
        needed_time[start*2] = needed_time[start] + 1

        if start*2 == K:
            cnt += 1

if N == K:
    cnt = 1

print(needed_time[K])
print(cnt)