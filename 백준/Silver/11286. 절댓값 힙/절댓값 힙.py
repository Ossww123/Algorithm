from collections import deque
import sys

# 절대값의 최소값(tree[0])을 빼내고 이진트리를 정렬합니다.
def tree_pop(tree):
    pop_num = tree.popleft()

    # 트리가 비었다면 빈 트리와 최소값(tree[0]) 반환
    if not tree:
        return tree, pop_num

    # 제일 끝에 있는 걸 인덱스[0]으로 땡겨오기
    tree.appendleft(tree.pop())
    parent = 0

    # 부모와 왼쪽 오른쪽 자식과 비교해서 자리바꾸기
    while True:
        left = 2 * parent + 1
        right = 2 * parent + 2
        abs_smallest = parent

        # left(right)가 존재하면서 절대값 조건에 맞지 않다면 자리바꾸기
        if left < len(tree):
            if abs(tree[left]) < abs(tree[abs_smallest]):
                abs_smallest = left
            elif abs(tree[left]) == abs(tree[abs_smallest]) and tree[left] < tree[abs_smallest]:
                abs_smallest = left
        if right < len(tree):
            if abs(tree[right]) < abs(tree[abs_smallest]):
                abs_smallest = right
            elif abs(tree[right]) == abs(tree[abs_smallest]) and tree[right] < tree[abs_smallest]:
                abs_smallest = right

        # 자리가 바꼈다면 바뀐 자리 갱신
        if abs_smallest != parent:
            tree[parent], tree[abs_smallest] = tree[abs_smallest], tree[parent]
            parent = abs_smallest
        else:
            break

    return tree, pop_num

# 값을 append하고 이진트리를 정렬합니다.
def tree_append(tree):
    child = len(tree) - 1
    while child > 0:
        parent = (child - 1) // 2
        if abs(tree[parent]) > abs(tree[child]):
            tree[parent], tree[child] = tree[child], tree[parent]
            child = parent
        elif abs(tree[parent]) == abs(tree[child]) and tree[parent] > tree[child]:
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
            tree, abs_min_value = tree_pop(tree)
            print(abs_min_value)
    else:
        tree.append(input_x)
        tree = tree_append(tree)