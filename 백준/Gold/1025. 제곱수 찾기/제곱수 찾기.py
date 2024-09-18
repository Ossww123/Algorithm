def is_sqrt(value):
    value = int(value)
    
    i = 0
    while i * i <= value:
        if i * i == value:
            return True
        i += 1
    
    return False

N, M = map(int,input().split())

arr = [list(input()) for _ in range(N)]

max_value = -1

for y in range(N):
    for x in range(M):
        for dy in range(-N, N+1):
            for dx in range(-M, M+1):
                value = ''
                ny, nx = y, x
                while True:
                    value += arr[ny][nx]
                    ny += dy
                    nx += dx
                    if int(value) > max_value and is_sqrt(value):
                        max_value = int(value)
                    if ny < 0 or ny >= N or nx < 0 or nx >= M:
                        break
                    if dy == dx == 0:
                        break
                # print(value)
                    

print(max_value)
        