import pprint

N = int(input())

home = [list(map(int, input().split())) for _ in range(N)]
h_d_v = [[[0,0,0] for _ in range(N+1)]for _ in range(N+1)]

for i in range(2, N+1):
    if home[0][i-1] == 1:
        break
    h_d_v[1][i][0] = 1

for y in range(2, N+1):
    for x in range(3, N+1):
        if home[y-1][x-1] == 1:
            continue

        h_d_v[y][x][0] = h_d_v[y][x-1][0]+ h_d_v[y][x-1][1]
        h_d_v[y][x][2] = h_d_v[y-1][x][1]+ h_d_v[y-1][x][2]
        
        if home[y-2][x-1] == 1 or home[y-1][x-2] == 1:
            continue 
        h_d_v[y][x][1] = sum(h_d_v[y-1][x-1])

print(sum(h_d_v[y][x]))
# pprint.pprint(h_d_v)