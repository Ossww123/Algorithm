dirs = [(-1, 0),(1, 0),(0, -1),(0, 1)]


# dfs를 수행합니다. 근처에 방문하지 않은 '1'을 찾아 is_baechu의 값을 True로 바꿉니다.

def dfs(matrix, is_baechu, first_y, first_x):
    stk = [(first_y, first_x)]
    is_baechu[first_y][first_x] = True

    while stk:
        first_y, first_x = stk.pop()
        for dx, dy in dirs:
            nx, ny = first_x + dx, first_y + dy
            if nx < 0 or nx >= w or ny < 0 or ny >= h:
                continue
            if matrix[ny][nx] == 0 or is_baechu[ny][nx]:
                continue
            is_baechu[ny][nx] = True
            stk.append((ny, nx))
        


# 입력을 받고 2차원 배열 matrix, 방문여부를 알려줄 is_baechu를 선언합니다.

T = int(input())
for tc in range(T):
    w, h, K = map(int, input().split())
    matrix = [[0] * w for _ in range(h)]
    is_baechu = [[False] * w for _ in range(h)]

# 배추의 위치를 표시합니다. 
    for _ in range(K):
        x, y = map(int, input().split())
        matrix[y][x] = 1

# matrix의 모든 요소를 탐색하며 dfs를 통해 컴포넌트의 개수를 셉니다.
    component = 0

    for y in range(h):
        for x in range(w):
            if matrix[y][x] == 0 or is_baechu[y][x]:
                continue
            else:
                dfs(matrix, is_baechu, y, x)
                component += 1
                
    print(component)
