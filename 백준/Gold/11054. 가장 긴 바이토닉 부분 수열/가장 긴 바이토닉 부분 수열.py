N = int(input())
lst = list(map(int,input().split()))
result = [[0,0] for _ in range(N)]

for i in range(N):
    max_cnt = 0
    for j in range(i):
        if lst[j] < lst[i]:
            max_cnt = max(max_cnt, result[j][0])
    result[i][0] = max_cnt + 1

for i in range(N-1,-1, -1):
    max_cnt = 0
    for j in range(N-1, i, -1):
        if lst[j] < lst[i]:
            max_cnt = max(max_cnt, result[j][1])
    result[i][1] = max_cnt + 1

max_value = 0
for i in range(N):
    temp = sum(result[i]) - 1 # 왼쪽부터 a번째, 오른쪽부터 b번째면 결과는 a+b-1
    max_value = max(temp, max_value)


print(max_value)