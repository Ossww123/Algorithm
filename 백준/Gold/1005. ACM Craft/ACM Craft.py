from collections import deque

# topological_sort

T = int(input())

for tc in range(T):
    N, K = map(int,input().split())
    time = [0] + list(map(int, input().split()))
    indegree = [0] * (N+1)
    que = deque()
    adj = [[] for _ in range(N+1)]

    for i in range(K):
        X, Y = map(int,input().split())
        adj[X].append(Y)
        indegree[Y] += 1

    result = [0] * (N + 1)

    for i in range(1, N+1):
        if indegree[i] == 0:
            result[i] = time[i]
            que.append(i)

    # 위상 정렬
    for _ in range(N):
        curr = que.popleft()
        for next_node in adj[curr]:
            # 최소 건설 완료 시간 갱신
            result[next_node] = max(result[next_node], result[curr] + time[next_node])
            # 간선을 삭제하여 next의 indegree가 0이 되면 next도 큐에 넣음
            indegree[next_node] -= 1
            if indegree[next_node] == 0:
                que.append(next_node)

    # 결과 출력
    r = int(input())
    print(result[r])