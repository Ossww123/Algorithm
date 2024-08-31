from collections import deque

def find_preorder(N, inorder, postorder):
    if N == 0:
        return

    value_to_index = {val: idx for idx, val in enumerate(inorder)}
    
    stack = deque([(0, N-1, 0, N-1)])
    result = []

    while stack:
        in_start, in_end, post_start, post_end = stack.pop()
        
        if in_start > in_end or post_start > post_end:
            continue
        
        root = postorder[post_end]
        result.append(root)
        
        if in_start == in_end:
            continue
        
        in_root = value_to_index[root]
        left_size = in_root - in_start
        
        stack.append((in_root + 1, in_end, post_start + left_size, post_end - 1))
        stack.append((in_start, in_root - 1, post_start, post_start + left_size - 1))
    
    return result

# 입력 받기
N = int(input())
inorder = list(map(int, input().split()))
postorder = list(map(int, input().split()))

# 전위 순회 결과 계산 및 출력
preorder = find_preorder(N, inorder, postorder)
print(*preorder)