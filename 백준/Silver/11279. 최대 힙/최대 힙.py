from collections import deque
import sys

# 최대값(tree[0])을 빼내고 이진트리를 정렬합니다.
def tree_pop(tree):
    pop_num = tree.popleft()
    if not tree:
        return tree, pop_num
    tree.appendleft(tree.pop())
    parent = 0
    while True:
        left = 2 * parent + 1
        right = 2 * parent + 2
        biggest = parent
        if left < len(tree) and tree[left] > tree[biggest]:
            biggest = left
        if right < len(tree) and tree[right] > tree[biggest]:
            biggest = right
        if biggest != parent:
            tree[parent], tree[biggest] = tree[biggest], tree[parent]
            parent = biggest
        else:
            break

    return tree, pop_num

# 값을 append하고 이진트리를 정렬합니다.
def tree_append(tree):
    child = len(tree) - 1
    while child > 0:
        parent = (child - 1) // 2
        if tree[parent] < tree[child]:
            tree[parent], tree[child] = tree[child], tree[parent]
            child = parent
        else:
            break
    return tree

N = int(input())
tree = deque([])

for _ in range(N):
    input_x = int(sys.stdin.readline().rstrip())
    if input_x == 0:
        if not tree:
            print(0)
        else:
            tree, max_value = tree_pop(tree)
            print(max_value)
    else:
        tree.append(input_x)
        tree = tree_append(tree)