N, M, K = map(int, input().split())

length = 1
while N > length:
    length <<= 1

tree = [1] * (length << 1)
# tree[length] ~ tree[length*2 -1] 까지가 리프 노드

for i in range(N):
    temp = int(input())
    tree[length + i] = temp

MOD = 1000000007

# 후위순회하면서 부모노드에 곱한 값 입력
def postorder(root):
    if root >= length*2:
        return 1
    if root >= length:
        return tree[root]
    left = postorder(root*2)
    right = postorder(root*2+1)
    tree[root] = (left * right) % MOD
    return tree[root]

postorder(1)

# 구간 곱을 구하는 함수
def query_product(left, right, node, node_left, node_right):
    if right < node_left or node_right < left:
        return 1
    if left <= node_left and node_right <= right:
        return tree[node]
    mid = (node_left + node_right) // 2
    return (query_product(left, right, node*2, node_left, mid) *
            query_product(left, right, node*2+1, mid+1, node_right)) % MOD

for _ in range(M+K):
    a, b, c = map(int, input().split())
    if a == 1:
        index = length + (b - 1)
        tree[index] = c
        while index > 1:
            index //= 2
            tree[index] = (tree[index*2] * tree[index*2 + 1]) % MOD
    elif a == 2:
        # 구간 b~c의 곱을 구하고 출력
        result = query_product(b-1, c-1, 1, 0, length-1)  # 인덱스를 0-based로 조정
        print(result)