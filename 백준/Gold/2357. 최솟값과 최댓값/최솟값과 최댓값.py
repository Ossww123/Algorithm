N, M = map(int, input().split())

length = 1
while N > length:
    length <<= 1

tree1 = [0] * (length << 1)  # 최댓값을 저장하는 트리
tree2 = [1e17] * (length << 1)  # 최솟값을 저장하는 트리

for i in range(N):
    temp = int(input())
    tree1[length + i] = temp
    tree2[length + i] = temp

def postorder1(root):
    if root >= length*2:
        return 0
    if tree1[root] != 0:
        return tree1[root]
    left = postorder1(root*2)
    right = postorder1(root*2+1)
    tree1[root] = max(left, right)
    return tree1[root]

postorder1(1)

def postorder2(root):
    if root >= length*2:
        return 1e17
    if tree2[root] != 1e17:
        return tree2[root]
    left = postorder2(root*2)
    right = postorder2(root*2+1)
    tree2[root] = min(left, right)
    return tree2[root]

postorder2(1)

def query_max(left, right):
    left += length
    right += length
    res = 0
    while left < right:
        if left & 1:
            res = max(res, tree1[left])
            left += 1
        if right & 1:
            right -= 1
            res = max(res, tree1[right])
        left >>= 1
        right >>= 1
    return res

def query_min(left, right):
    left += length
    right += length
    res = 1e17
    while left < right:
        if left & 1:
            res = min(res, tree2[left])
            left += 1
        if right & 1:
            right -= 1
            res = min(res, tree2[right])
        left >>= 1
        right >>= 1
    return res

for _ in range(M):
    a, b = map(int, input().split())
    min_val = query_min(a-1, b)
    max_val = query_max(a-1, b)
    print(min_val, max_val)
# i = 1
# while True:
#     print(tree1[i:i*2])
#
#     i *= 2
#     if i > len(tree1):
#         break
#
# i = 1
# while True:
#     print(tree2[i:i * 2])
#
#     i *= 2
#     if i > len(tree1):
#         break