DIRS = [(0, 1), (0, -1), (1, 0), (-1, 0)]
clock_dirs = [(-1, 0), (0, 1), (1, 0), (0, -1)]
Rclock_dirs = [(1, 0), (0, 1), (-1, 0), (0, -1)]

R, C, T = map(int, input().split())
array = [list(map(int, input().split())) for _ in range(R)]

for y in range(R):
    if array[y][0] == -1:
        air_purifier = (y, 0)
        break


# 미세먼지 확산 시뮬레이션
def dust_spread():
    # 미세먼지 증감을 기록할 배열
    temp_array = [[0] * C for _ in range(R)]

    for y in range(R):
        for x in range(C):

            # 확산될 일이 없으면 패스
            if array[y][x] < 5:
                continue

            spread_num = array[y][x] // 5

            for dy, dx in DIRS:
                ny, nx = y + dy, x + dx

                # 범위 밖이거나 공기 청정기가 있으면 패스
                if ny < 0 or ny >= R or nx < 0 or nx >= C:
                    continue
                if array[ny][nx] == -1:
                    continue

                temp_array[ny][nx] += spread_num
                temp_array[y][x] -= spread_num

    # 기록된 증감을 입력
    for y in range(R):
        for x in range(C):
            array[y][x] += temp_array[y][x]


# 공기청정기 가동 시뮬레이션
def run_air_purifier():
    # 위쪽 공기청정기
    currY, currX = air_purifier
    currY -= 1
    dir = 0

    while True:
        if (currY, currX - 1) == air_purifier:
            array[currY][currX] = 0
            break

        nextY = currY + clock_dirs[dir][0]
        nextX = currX + clock_dirs[dir][1]

        if nextY < 0 or nextY > y or nextX < 0 or nextX >= C:
            dir += 1
            continue

        array[currY][currX] = array[nextY][nextX]
        currY, currX = nextY, nextX


    # 아래쪽 공기청정기
    currY, currX = air_purifier
    currY += 2
    dir = 0

    while True:
        if (currY - 1, currX - 1) == air_purifier:
            array[currY][currX] = 0
            break

        nextY = currY + Rclock_dirs[dir][0]
        nextX = currX + Rclock_dirs[dir][1]

        if nextY <= y or nextY >= R or nextX < 0 or nextX >= C:
            dir += 1
            continue

        array[currY][currX] = array[nextY][nextX]
        currY, currX = nextY, nextX


# T번 실행
for _ in range(T):
    dust_spread()
    run_air_purifier()

# 남은 미세먼지 계산
total = 0
for y in range(R):
    for x in range(C):
        if array[y][x] > 0:
            total += array[y][x]

print(total)