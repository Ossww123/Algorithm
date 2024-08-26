N = int(input())
tree = {}
island_info = [['S', 0]]
for i in range(1, N):
    animal, num, island = input().split()
    island_info.append((animal, int(num), int(island) - 1))
    tree.setdefault(int(island) - 1, []).append(i)


# 스택을 사용한 반복적 후위 탐색
def iterative_postorder_traversal(root):
    if root not in tree:
        return [root]

    stack = [(root, False)]
    orders = []

    while stack:
        node, visited = stack.pop()
        if visited:
            orders.append(node)
        else:
            stack.append((node, True))
            if node in tree:
                for child in reversed(tree[node]):
                    stack.append((child, False))

    return orders


orders = iterative_postorder_traversal(0)

survived_sheeps = [0] * N
for i in orders:
    if i in tree:
        for j in tree[i]:
            survived_sheeps[i] += survived_sheeps[j]

    if island_info[i][0] == 'S':
        survived_sheeps[i] += island_info[i][1]
    else:
        survived_sheeps[i] = max(0, survived_sheeps[i] - island_info[i][1])

print(survived_sheeps[0])