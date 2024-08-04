T = int(input())

for tc in range(1, T+1):
    t_c = int(input())
    numbers = list(map(int, input().split()))
    numbers.sort()
    max_cnt = 0
    cnt = 1
    result = numbers[0]
    for i in range(1, len(numbers)):
        if numbers[i] == numbers[i-1]:
            cnt += 1
            if cnt >= max_cnt:
                max_cnt = cnt
                result = numbers[i]
        else:
            cnt = 1
    print(f"#{tc} {result}")