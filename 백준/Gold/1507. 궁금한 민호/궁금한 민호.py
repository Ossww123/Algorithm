from pprint import pprint as pp

N = int(input())
INF = 1e17

# 원본 그래프 입력 받기
original = [list(map(int, input().split())) for _ in range(N)]

flag = False
# 플로이드 와샬 알고리즘으로 최단 거리 계산
dist = [row[:] for row in original]
for k in range(N):
    for i in range(N):
        for j in range(N):
            if dist[i][j] != min(dist[i][j], dist[i][k] + dist[k][j]):
                flag = True
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])


# 필수 간선을 찾기 위한 함수
def is_essential(i, j):
    if i == j:
        return False
    for k in range(N):
        if k != i and k != j and dist[i][j] == dist[i][k] + dist[k][j]:
            return False
    return True

# 필수 간선만 남긴 새로운 그래프 생성
essential = [[0 if i == j else INF for j in range(N)] for i in range(N)]
for i in range(N):
    for j in range(N):
        if is_essential(i, j):
            essential[i][j] = original[i][j]

result = 0
for i in range(N):
    lst = list(map(lambda x: 0 if x >= 1e17 else x, essential[i]))
    result += sum(lst)

result //= 2
if flag:
    print(-1)
else:
    print(result)

'''
input:
5
0 6 15 2 6
6 0 9 8 12
15 9 0 16 18
2 8 16 0 4
6 12 18 4 0
'''