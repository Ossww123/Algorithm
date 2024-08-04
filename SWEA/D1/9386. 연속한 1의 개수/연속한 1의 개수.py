T = int(input())

for tc in range(1, T+1):
    N = int(input())
    numbers = list(map(int, input()))
    cnt = 0
    max_cnt = 0
    for i in numbers:
        if i == 1:
            cnt += 1
            max_cnt = max(max_cnt, cnt)
        else:
            cnt = 0
    result = max_cnt

    print(f"#{tc} {result}")