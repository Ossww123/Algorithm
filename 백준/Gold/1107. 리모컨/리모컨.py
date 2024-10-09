N = int(input())
M = int(input())

# 문자형으로 숫자 받기
if M > 0:
    broken_buttons = list(input().split())

# 기본값
min_cnt = abs(N - 100)
up, down = N, N

# 숫자 다 고장난 경우 결과는 기본값
if M == 10:
    pass

# 숫자 다 멀쩡한 경우 결과
elif M == 0:
    min_cnt = min(min_cnt, len(str(N)))

else:
    cnt = 0

    while True:
        # 1씩 +, - 하면서 고장난 버튼의 숫자가 있는지 확인
        
        for broken_button in broken_buttons:
            if broken_button in str(down):
                break
        else:
            # 기본값과 채널번호의 길이 + cnt 중 작은 값 입력
            min_cnt = min(min_cnt, len(str(down)) + cnt)
            break
        
        for broken_button in broken_buttons:
            if broken_button in str(up):
                break
        else:
            # 기본값과 채널번호의 길이 + cnt 중 작은 값 입력
            min_cnt = min(min_cnt, len(str(up)) + cnt)
            break

        up += 1
        if down > 0:
            down -= 1
        cnt += 1

print(min_cnt)