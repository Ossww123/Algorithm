T = int(input())

for tc in range(T):
    x, y = map(int, input().split())
    distance = y-x
    speed = 0
    cnt = 0

    while distance:
        if speed * (speed + 1) // 2 + (speed + 1) <= distance:
            speed += 1
            distance -= speed
        elif speed * (speed - 1) // 2 + speed <= distance or speed == 1:
            distance -= speed
        else:
            speed -= 1
            distance -= speed
        cnt += 1

    print(cnt)
