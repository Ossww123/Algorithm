from collections import deque

T = int(input())

for tc in range(T):
    K, M, P = map(int, input().split())

    adj = [[] for _ in range(M)]
    indegree = [0] * M
    Strahler = [0] * M

    for i in range(P):
        before, after = map(lambda x: int(x) - 1, input().split())
        indegree[after] += 1
        adj[before].append(after)

    que = deque()
    for i in range(M):
        if indegree[i] == 0:
            que.append(i)
            Strahler[i] = 1

    inStrahler = [[] for _ in range(M)]

    for _ in range(M):
        start = que.popleft()

        for next_node in adj[start]:
            indegree[next_node] -= 1
            inStrahler[next_node].append(Strahler[start])
            # if Strahler[next_node] == Strahler[start]:
            #     Strahler[next_node] = Strahler[start] + 1
            # elif Strahler[next_node] < Strahler[start]:
            #     Strahler[next_node] = Strahler[start]

            if indegree[next_node] == 0:
                que.append(next_node)

                if len(inStrahler[next_node]) == 1:
                    Strahler[next_node] = inStrahler[next_node][0]
                else:
                    temp = sorted(inStrahler[next_node])
                    Strahler[next_node] = temp[-1] + 1 if temp[-1] == temp[-2] else temp[-1]

    print(f'{K} {Strahler[M-1]}')