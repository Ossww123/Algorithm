from collections import deque


def topological_sort():
    N = int(input())
    time = [0] * N
    result = [0] * N
    indegree = [0] * N
    adj = [[] for _ in range(N)]
    Q = deque()

    for i in range(N):
        inputs = list(map(int, input().split()))
        time[i] = inputs[0]
        for pre in inputs[1:-1]:
            indegree[i] += 1
            adj[pre - 1].append(i)

        # indegree가 0인 정점을 큐에 넣음
        if indegree[i] == 0:
            result[i] = time[i]
            Q.append(i)

    # 위상 정렬
    for _ in range(N):
        curr = Q.popleft()
        for next_node in adj[curr]:
            # 최소 건설 완료 시간 갱신
            result[next_node] = max(result[next_node], result[curr] + time[next_node])
            # 간선을 삭제하여 next의 indegree가 0이 되면 next도 큐에 넣음
            indegree[next_node] -= 1
            if indegree[next_node] == 0:
                Q.append(next_node)

    # 결과 출력
    for r in result:
        print(r)


topological_sort()