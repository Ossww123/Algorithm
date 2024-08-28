r, c = map(int, input().split())
maps = []
for _ in range(r):
    maps.append(list(input()))
ans = 0
used = set()
DIRS = [(0,1),(0,-1),(1,0),(-1,0)]
def dfs(x, y, count):
    global ans
    ans = max(ans, count)
    for dy, dx in DIRS:
        ny, nx = y + dy, x + dx
        if 0 <= nx < r and 0 <= ny < c and not maps[nx][ny] in used:
            used.add(maps[nx][ny])
            dfs(nx, ny, count+1)
            used.remove(maps[nx][ny])
used.add(maps[0][0])
dfs(0, 0, 1)
print(ans)