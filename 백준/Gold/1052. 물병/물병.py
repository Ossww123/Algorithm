def check_one(num):
    cnt = 0
    while num != 0:
        if num & 1:
            cnt += 1
        num >>= 1

    return cnt

N, K = map(int,input().split())

# 2진수로 바꿨을 때 1이 몇개 있는지 확인
cnt = 0
while True:
    curr = check_one(N)
    if K >= curr:
        break;

    # K보다 1이 많다면 1L물통 하나 추가
    N += 1
    cnt += 1

print(cnt)