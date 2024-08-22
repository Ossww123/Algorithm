def dfs(node, selected, visited, result):
    current = node
    path = []

    while not visited[current]:
        visited[current] = True
        path.append(current)
        current = selected[current]

    if current in path:
        cycle_start = path.index(current)
        result.update(path[cycle_start:])


T = int(input())

for _ in range(T):
    N = int(input())
    selected_students = list(map(lambda x: int(x) - 1, input().split()))

    visited = [False] * N
    result = set()

    for i in range(N):
        if not visited[i]:
            dfs(i, selected_students, visited, result)

    print(N - len(result))