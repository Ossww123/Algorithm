N = int(input())
edges = []

for _ in range(N):
    a, b = map(int, input().split())
    edges.append((a, b))

edges.sort(key = lambda x : (x[0], x[1]))
count = 1


for edge in edges:
    if edge == edges[0]:
        value = edge
    else:
        if edge[0] >= value[0] and edge[1] < value[1]:
            value = edge

        elif edge[0] >= value[1]:
            value = edge

            count += 1

print(count)


'''
a, b
정렬했으니 항상 아래 조건을 만족
a1 <= a2

나올 수 있는 경우

--- a2 < b1일때
1. a1 < a2, b1 < b2
그냥 컷
2. a1 = a2, b1 < b2
그냥 컷
3. a1 = a2, b1 = b2
겹치는게 있나?
4. a1 < a2, b1 = b2
(0 4)를 (1 4) 로 바꿀 수도 있지만 별로 의미가 없다.

결국 하는게 없음

5. a1 <= a2, b1 > b2
value 갈아 치우기


--- a2 >= b1일때
value 갈아치우기
count += 1
'''
