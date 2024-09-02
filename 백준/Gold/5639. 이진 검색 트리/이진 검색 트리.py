import sys
sys.setrecursionlimit(100000)

def build_binary_tree(numbers):
    if not numbers:
        return None

    root = numbers[0]
    tree = {root: [None, None]}

    for num in numbers[1:]:
        current = root
        while True:
            if num < current:
                if tree[current][0] is None:
                    tree[current][0] = num
                    tree[num] = [None, None]
                    break
                current = tree[current][0]
            else:
                if tree[current][1] is None:
                    tree[current][1] = num
                    tree[num] = [None, None]
                    break
                current = tree[current][1]

    return tree

def postorder_traversal(tree, node):
    if tree[node][0]:
        postorder_traversal(tree, tree[node][0])
    if tree[node][1]:
        postorder_traversal(tree, tree[node][1])
    print(node)

# Example usage
numbers = []
while True:
    try:
        num = int(input())
        numbers.append(num)
    except:
        break

if numbers:
    tree = build_binary_tree(numbers)
    postorder_traversal(tree, numbers[0])
else:
    print(numbers[0])