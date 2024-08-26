from collections import deque

N = int(input())

# 섬의 양(늑대) 수를 표시
lst = [0] * N

# i번째 노드가 가지는 자식의 수
children_num = [0] * N

# i번째 노드의 부모
parents = [0] * N

for idx in range(1, N):
    animal, num, island = input().split()
    num = int(num)
    island = int(island) - 1
    
    # 양이면 양수로 저장, 늑대면 음수로 저장
    lst[idx] = num if animal == 'S' else -num

    children_num[island] += 1
    parents[idx] = island

que = deque()

# 자식의 수가 0이다 == 트리의 가장 깊은 부분
for idx in range(N):
    if not children_num[idx]:
        que.append(idx)

while que:
    now = que.popleft()

    # 1번 섬이면 끝
    if now == 0:
        break

    parent = parents[now]

    # 살아남은 양이 있다면 부모에게 전달
    if lst[now] > 0:
        lst[parent] += lst[now]

    # 자식 노드의 양을 다 계산 했다면 다음 계산
    children_num[parent] -= 1
    if not children_num[parent]:
        que.append(parent)

print(lst[0])